#!/bin/bash

#1) Realizar un script que reciba dos archivos por parametro, y que muestre por pantalla el nombre del archivo de mayor tamanio y su nombre. Y si son iguales mostrar el mensaje "son iguales"
#

if [ $# -ne 2 ]; then
	echo "Ingrese dos archivos como argumentos"
	exit 1
fi

arch1=$1
arch2=$2

if [ ! -f $arch1 ]; then
	echo "Error: $arch1 no es un archivo"
	exit 1
fi

if [ ! -f $arch2 ]; then
	echo "Error: $arch2 no es un archivo"
	exit 1
fi

tam_arch1=$(du -b $arch1 | cut -f 1) 
tam_arch2=$(du -b $arch2 | cut -f 1) 

if [ $tam_arch1 -gt $tam_arch2 ]; then
	
	echo "El archivo: $arch1 es mayor que, $arch2"

elif [ $tam_arch1 -lt $tam_arch2 ]; then

	echo "El archivo: $arch2 es mayor que, $arch1"

else
	echo "Son iguales"
fi
