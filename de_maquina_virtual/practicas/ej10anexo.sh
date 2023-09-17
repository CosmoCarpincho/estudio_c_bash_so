#!/bin/bash
#
#10- Hacer un script que reciba un directorio cualquiera pasado por parámetro, y calcule la cantidad de líneas de cada uno de sus archivos ordinarios (comunes), además contabilizar el total de líneas de todos los archivos y guardarlo en el archivo TOT_GENEARAL

if [ -f TOT_GENERAL ]
then
	echo "" > TOT_GENERAL
else
	touch TOT_GENERAL
fi

dir=$1
total=0

for archivo in $(find $dir -maxdepth 1 -type f)
do
	echo $archivo
	wc -l $archivo | awk '{print "El archivo", $2, "tiene", $1, "lineas"}' >> TOT_GENERAL

	lineas=$(wc -l $archivo | cut -d " " -f 1)
	((total+=lineas))

done

echo "El total de lineas de todos los archivos es:" $total >> TOT_GENERAL

# Forma con find y awk
#find $dir -type f -exec wc -l {} + 2> /dev/null | awk '!/total/ {total+=$1; print "El archivo:", $2, "tiene", $1, "lineas"} END {print "El total de lineas de todos los archivos es:",total}'

