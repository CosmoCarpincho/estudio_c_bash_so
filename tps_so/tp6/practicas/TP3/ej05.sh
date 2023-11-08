#!/bin/bash
#5- Usando una estructura repetitiva recorrer un directorio 
#cualquiera pasado por parámetro y determinar que archivos fueron 
#modificados (Comnado stat) en un mes determinado. Dicho mes también 
#pasarlo por parámetro.

if [ $# -ne 2 ] || [ $1 -lt 1 -o $1 -gt 12 -o ! -d $2 ]; then
	 echo "Error"
	 echo "Formato: <mes> (en numero) <directorio>"
	 exit 1
fi

mes=$1
dir=$2

echo "Archivos modificados en el mes $mes son:"
for archivo in $(find $dir -maxdepth 1 -type f); do

	mes_arc=$(stat -c '%z' "$archivo" | cut -d '-' -f2)

	if (( $mes == $mes_arc ))
	then
		echo "$archivo"
	fi

done
