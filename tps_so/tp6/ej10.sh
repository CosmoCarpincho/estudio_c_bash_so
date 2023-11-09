#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Ingrese un usuario"
	exit 2
fi

usuario=$1

ultimo_mes=$(date +%b)

cant_ultimo_mes=$(last $usuario | grep -i $ultimo_mes | wc -l)

if [ $cant_ultimo_mes -eq "0" ]; then
	echo "El usuario: $usuario no se conecto el ultimo mes"
else
	echo "El usuario: $usuario estuvo conectado el ultimo mes"
fi
