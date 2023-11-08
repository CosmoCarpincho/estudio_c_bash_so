#!/bin/bash
# 4- Usando el comando find, generar un scrip que al pasarle un directorio cualquiera pasado como parámetro: a) Guarde en el archivo name los nombres de archivos que comienzan con la letra a. b) Guarde en el archivo extend los nombres de archivos que tienen extensión .txt c) Guarde en el archivo perm los nombre de archivos que tienen permisos iguales a 644 d) Guarde en el archivo tam los nombres de archivos que tienen tamaño mayor a 1K 

if [ $# -ne 1 -o ! -d $1 ]; then
	echo "Ingrese un directorio valido"
	exit 1
fi

dir=$1

find $dir -iname "a*" -type f -printf "%f\n" > name
find $dir -iname "*.txt" -type f  -printf "%f\n" > extend
find $dir -perm 644 -type f -printf "%f\n" > perm
find $dir -size +1k -type f -printf "%f\n" > tam

