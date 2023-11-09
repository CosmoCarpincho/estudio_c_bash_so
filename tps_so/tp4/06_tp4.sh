#!/bin/bash
#

if [ $# -ne 1 ]; then
	echo "Ingrese el valor a cortar"
	exit 2
fi

value=$1

for i in {1..10}; do
	echo "iteracion : $i"
	pgrep $(basename $0)

	if [ $value -eq $i ]; then
		echo "se sale en $i"
		break
	fi

	sleep 2
done
