#include <iostream>
#include <thread>
#include "MessageQueue.h"
#include "ProcesoProduccionAnodos.h"
#include "ProcesoCeldas.h"
#include "ProcesoColada.h"

int main() {
    MessageQueue<std::string> colaMensajes;

    ProcesoProduccionAnodos anodos(&colaMensajes);
    ProcesoCeldas celdas(&colaMensajes);
    ProcesoColada colada(&colaMensajes);

    std::thread hiloAnodos(&ProcesoProduccionAnodos::producir, &anodos);
    std::thread hiloCeldas(&ProcesoCeldas::operar, &celdas);
    std::thread hiloColada(&ProcesoColada::operar, &colada);

    hiloAnodos.join();
    hiloCeldas.join();
    hiloColada.join();

    return 0;
}
