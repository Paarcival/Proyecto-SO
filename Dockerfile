# Usa una imagen base con soporte para C++
FROM alpine:latest
RUN apk add --no-cache g++ make
# Establece el directorio de trabajo dentro del contenedor
WORKDIR /app

# Copia todos los archivos fuente al contenedor
COPY . /app

# Compila el programa
RUN g++ -std=c++17 -pthread -o main monitor.cpp

# Define el comando que se ejecutará al iniciar el contenedor
CMD ["./main"]
