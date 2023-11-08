#!/bin/bash
#

if [ $# -ne 1 ]; then
	echo "Ingrese un directorio"
	exit 3
fi

if [ ! -d $1 ]; then
	echo "Lo ingresado no es un directorio"
	exit 4
fi

dir=$1

find $dir -maxdepth 1 -type f -name "*.mp3" -delete # borra todos los mp3
# si quiero que borre todos los mp3 recursivamente sacar el maxdepth

if [ ! -d $dir/exe/ ]; then
	mkdir $dir/exe
fi

find $dir -type f -perm 744 -exec cp {} $dir/exe/ \;
