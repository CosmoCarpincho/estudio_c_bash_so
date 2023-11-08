#!/bin/bash
#
# 4. Idem anterior pero pasando los archivos por parametro


if [ $# -ne 2 ]; then
	echo "Error: Ingrese dos parametros"
	exit 1
fi

if [ ! -f $1 -o ! -f $2 ]; then
	echo "Error: los parametros tienen que ser archivos"
	exit 1
fi

arch1=$1
arch2=$2

cant1=$(wc -l $arch1 | cut -d " " -f 1)
cant2=$(wc -l $arch2 | cut -d " " -f 1)

if [ $cant1 -gt $cant2 ]; then
	echo "El archivo $arch1 ($cant1 lineas) es mayor que $arch2 ($cant2 lineas)"
elif [ $cant1 -lt $cant2 ]; then
	echo "El archivo $arch2 ($cant2 lineas) es mayor que $arch1 ($cant1 lineas)"
else
	echo "Los archivos tienen las mismas lineas => $cant1"
fi
