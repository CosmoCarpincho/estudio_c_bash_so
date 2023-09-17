#!/bin/bash
#
#2) Realizar un script que reciba un directorio como parametro copie a un derectorio llamado nuevo todos los archivos que contengan en su interir la palabra bash
#

if [ $# -ne 1 ]; then
	echo "Ingrese un directorio"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "El parametro tiene que ser un directorio"
	exit 1
fi

if [ -d "./nuevo" ]; then
	rm -r nuevo # Limpia todo el directorio
	mkdir nuevo
else
	mkdir nuevo
fi

dir=$1

for archivo in $(find $dir -type f); do

	cant_bash_arch=$(grep -c 'bash' $archivo)

	if [ $cant_bash_arch -gt 0 ]; then
		echo "Archivo copiado: $archivo"
		cp $archivo nuevo/
	fi

done
