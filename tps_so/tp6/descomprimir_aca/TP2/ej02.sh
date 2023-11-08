#!/bin/bash
#
# Hacer un escript que relaice los siguientes pasos
# - Limpiar la pantalla
# - Ejecutar el comando df
# - Buscar en la salidad del comando anterior el espacio disponible en el sistema de archivos raiz
# El espacio disponible en el sistema de archivos raiz es: xxxx

clear
df -h | awk '/\/$/ {print "El espacio disponible en el sistema de archivos raiz es:",$4}'

# Otra forma

echo "El espacio disponible en el sistema de archivos raiz es:" $(df -h | grep '\/$' | tr -s " " | cut -d " " -f 4)
