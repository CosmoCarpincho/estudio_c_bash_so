#!/bin/bash

dir=$1

if [ $# -ne 1 ]; then
	echo "Ingrese el número de parametros correcto"
	exit 13 #numeros positivos
fi

if [ ! -d $dir ]; then
	echo "Ingres un directorio"
	exit 14
fi

# muy complicado con find
# el type es para que no agarre los links
#find $dir -type f,d -exec du {} \;

echo "** Arch:"
cant_arch=0
cant_dir=0

for archivo in $(find $dir -type f); do
	((cant_arch++))
	du -h $archivo
done

echo -e "\nCantidad de archivos: $cant_arch\n\n\n** Dir:"

for directorio in $(find $dir -mindepth 1 -type d); do
	((cant_dir++))
	# el -d 0 es para indicar que solo revise lo que se le pasa.
	# -d, --max-depth=N
	# --summarize, -s es igual que -d 0
	du -s -h $directorio
done

echo -e "\nCantidad de directorios: $cant_dir"
