#!/bin/bash

if [[ -f $1 ]];then
	cat $1
else
	echo "No existe el archivo"
fi
