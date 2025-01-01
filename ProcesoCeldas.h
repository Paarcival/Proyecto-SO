#ifndef PROCESO_CELDAS_H
#define PROCESO_CELDAS_H

#include <iostream>
#include <thread>
#include <chrono>
#include "MessageQueue.h"

class ProcesoCeldas {
private:
    static const int DESGASTE_MAXIMO = 100;
    int desgasteAnodo;
    int produccionAluminio;
    MessageQueue<std::string>* colaMensajes;

public:
    ProcesoCeldas(MessageQueue<std::string>* cola) : desgasteAnodo(0), produccionAluminio(0), colaMensajes(cola) {}

    void operar() {
        while (true) {
            if (!colaMensajes->empty()) {
                std::string mensaje = colaMensajes->receive();
                if (mensaje == "ANODO_DISPONIBLE") {
                    desgasteAnodo = 0;
                    std::cout << "[Celdas] Ánodo reemplazado. Producción reanudada." << std::endl;
                }
            } else {
                if (desgasteAnodo < DESGASTE_MAXIMO) {
                    desgasteAnodo += 10;
                    produccionAluminio += 50;

                    // Enviar mensaje de producción a la cola
                    colaMensajes->send("ALUMINIO_PRODUCIDO");

                    std::cout << "[Celdas] Produciendo aluminio. Desgaste del ánodo: " << desgasteAnodo << "%" << std::endl;
                } else {
                    std::cout << "[Celdas] Ánodo desgastado. Solicitando reemplazo." << std::endl;
                    colaMensajes->send("REQUEST_ANODO");
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

#endif
