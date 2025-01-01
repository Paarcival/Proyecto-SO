#ifndef PROCESO_PRODUCCION_ANODOS_H
#define PROCESO_PRODUCCION_ANODOS_H

#include <iostream>
#include <thread>
#include <chrono>
#include "MessageQueue.h"

class ProcesoProduccionAnodos {
private:
    int anodosDisponibles;
    MessageQueue<std::string>* colaMensajes;

public:
    ProcesoProduccionAnodos(MessageQueue<std::string>* cola) : anodosDisponibles(10), colaMensajes(cola) {}

    void producir() {
        while (true) {
            if (!colaMensajes->empty()) {
                std::string mensaje = colaMensajes->receive();
                if (mensaje == "REQUEST_ANODO") {
                    if (anodosDisponibles > 0) {
                        anodosDisponibles--;
                        std::cout << "[Ánodos] Ánodo entregado. Restantes: " << anodosDisponibles << std::endl;
                        colaMensajes->send("ANODO_DISPONIBLE");
                    } else {
                        std::cout << "[Ánodos] No hay ánodos disponibles." << std::endl;
                        colaMensajes->send("ANODO_NO_DISPONIBLE");
                    }
                }
            } else {
                // Producción autónoma
                if (anodosDisponibles < 10) {
                    anodosDisponibles++;
                    std::cout << "[Ánodos] Produciendo ánodo. Disponibles: " << anodosDisponibles << std::endl;
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

#endif
