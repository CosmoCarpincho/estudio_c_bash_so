#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Ingrese un filtro"
	exit 2
fi

filtro=$1

if [[ ! $filtro =~ ^alert$|^crit$|^err$|^warn$|^notice$|^info$|^debug$ ]]; then
	echo "Ingrese un filtro correcto."
	echo "Filtros: alert crit err warn notice info debug"
	exit 3
fi

sudo dmesg -HTx --level $filtro

echo "== FIN =="
