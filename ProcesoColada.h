#ifndef PROCESO_COLADA_H
#define PROCESO_COLADA_H

#include <iostream>
#include <thread>
#include <chrono>
#include "MessageQueue.h"

class ProcesoColada {
private:
    int almacen;
    MessageQueue<std::string>* colaMensajes;

public:
    ProcesoColada(MessageQueue<std::string>* cola) : almacen(0), colaMensajes(cola) {}

    void operar() {
        while (true) {
            if (!colaMensajes->empty()) {
                std::string mensaje = colaMensajes->receive();
                if (mensaje == "ALUMINIO_PRODUCIDO") {
                    almacen += 50;
                    std::cout << "[Colada] Colando aluminio. Total almacenado: " << almacen << "kg." << std::endl;
                }
            } else {
                // Estado autónomo cuando no hay mensajes
                std::cout << "[Colada] Esperando aluminio para colar." << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
};

#endif
