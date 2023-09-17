#!/bin/bash
#
# Diferencia entre inicializar i con [ y no inicializarlo con [[ 

i=0
while [ $i -lt 10 ]; do
	echo "Con [ $i"
	((i++))
done

while [[ $i2 -lt 10 ]]; do
	echo "Con [[ $i2"
	((i2++))
done
