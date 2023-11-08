#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Ingrese un directorio"
	exit 2
fi

if [ ! -d $1 ]; then
	echo "No es un directorio lo ingresado"
	exit 3
fi

dir=$1

max_tam=0
max_nom=''
for archivo in $(find $dir -maxdepth 1 -type f); do

	tam_arch=$(du $archivo | awk '{print $1}')
	nom_arch=$(du $archivo | awk '{print $2}')

	if [ $max_tam -lt $tam_arch ]; then
		max_tam=$tam_arch
		max_nom=$nom_arch
	fi
done

echo "El archivo de mayor manaño es: $nom_arch y su tamaño es de $tam_arch K"
