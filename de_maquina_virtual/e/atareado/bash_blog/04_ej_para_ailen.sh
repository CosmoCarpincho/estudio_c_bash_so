#!/bin/bash

directorio=$1
cantDir=0
cantArch=0

if [[ ! -d $directorio ]]; then
	echo "El directorio no existe."
	exit
fi

for i in $directorio/*; do
	if [[ -d $i ]]; then
		((cantDir=$cantDir+1))
	elif [[ -f $i ]]; then
		((cantArch=$cantArch+1))
	fi
done
echo "La cantidad de archivos es: " $cantArch
echo "La cantidad de archivos es: " $cantDir
