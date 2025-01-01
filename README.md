# **Sistema de Producción de Aluminio en Celdas Hall-Héroult**

Este proyecto implementa un sistema simulado de producción de aluminio en celdas Hall-Héroult, diseñado en **C++** y preparado para ejecutarse en un entorno de **Docker**. El sistema está compuesto por tres procesos principales que se comunican entre sí mediante el paso de mensajes, garantizando un flujo continuo y coordinado de la producción.

---

## **Procesos del Sistema**

1. **Producción de Ánodos**:
   - Simula la producción y suministro de ánodos utilizados en las celdas.
   - Cuando las celdas solicitan un ánodo, verifica la disponibilidad y los entrega.
   - Si no hay solicitudes, continúa produciendo ánodos de manera autónoma.

2. **Producción en Celdas**:
   - Simula el proceso de producción de aluminio mediante electrolisis.
   - Consume ánodos durante la producción y solicita reemplazos cuando se desgastan.
   - Genera aluminio y envía notificaciones a la colada para procesar el material.

3. **Proceso de Colada**:
   - Recibe el aluminio producido por las celdas.
   - Coloca el aluminio en moldes y lo almacena.
   - Si no hay aluminio disponible, espera nuevas producciones.

---

## **Características Principales**

- **Orientación a Objetos**: El sistema está diseñado utilizando clases para encapsular la lógica de cada proceso.
- **Comunicación por Mensajes**: Los procesos se comunican a través de una cola de mensajes (`MessageQueue`), asegurando una interacción fluida y sincronizada.
- **Multithreading**: Cada proceso se ejecuta en un hilo independiente para simular una operación paralela y realista.
- **Docker Ready**: El proyecto está preparado para ejecutarse dentro de un contenedor Docker, facilitando la portabilidad y la reproducción del entorno.

---

## **Requisitos**

- **C++17** o superior.
- Docker instalado en el sistema.

---

## **Instrucciones de Ejecución**

### **Ejecutar en el entorno local**
1. Clona este repositorio:
   ```bash
   git clone https://github.com/Paarcival/Proyecto-SO.git
   cd Proyecto-SO/
2. Compilar proyecto a imagen docker
   ```bash
   sudo docker build -t produccion-aluminio  .
3. Crear contenedor con la imagen
   ```bash
   sudo docker run -d --rm --name produccion produccion-aluminio

## **Ver logs del contenedor**
   ```bash
   sudo docker logs  produccion
   ```
Nota: Estos ejemplos son con el nombre para la imagen y para el contenedor, pero estos pueden ser cambiados.
