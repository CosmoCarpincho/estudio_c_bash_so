#!/bin/bash

dir=$1
echo $dir

dir_copy="BackupDir"

if [ $# -ne 1 ]; then
	echo "Ingrese un parametro"
	exit
fi

if [ ! -d $dir ]; then
	echo "Lo ingresado no es un directorio"
	exit
fi

if [ ! -d $dir_copy ]; then
	mkdir $dir_copy
fi

find $dir -type f -iname "*.sh" -exec cp {} $dir_copy/{} \;
