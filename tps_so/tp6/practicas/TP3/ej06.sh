#!/bin/bash
#
## 6- Hacer un informe de un directorio cualquiera pasado por
## parámetro que indique:
## a) Que archivos han sido modificados en los últimos 30 minutos
## b) Que archivos han sido accedidos en los últimos 60 minutos.
## c) Que archivos han sido modificados en los últimos 5 dias
## d) Que archivos han sido modificados hace más de 10 dias


if [ $# -ne 1 -o ! -d "$1" ]; then
	echo "Error"
	echo "Ingrese un directorio valido"
fi
dir=$1

echo -e "Modificados ultimos 30 dias\n" > informe.txt

find $dir -type f -mmin -30 >> informe.txt

echo -e "\nAccedidos en los ultimos 60 minutos\n" >> informe.txt

find $dir -type f -amin -60 >> informe.txt

echo -e "\nModificados en los ultimos 5 dias\n" >> informe.txt

find $dir -type f -mtime -5 >> informe.txt

echo -e "\nmodificados hace mas de 10 dias\n" >> informe.txt

find $dir -type f -mtime +10 >> informe.txt

