#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Ingrese el valor de memoria de referencia"
	exit 2

fi

valor=$1

while [ true ]; do
	echo "Cada 5 segundo"
	mem_usada=$(free | head -n 2 | tail -n 1 | awk '{printf $3}')
	if [ $mem_usada -gt $valor ]; then
		echo "Se supero la memora de referencia $valor"
		echo "PELIGRO = La memoria actual es $mem_usada"
	fi
	sleep 5

done
