#!/bin/bash

# 10. Copiar el archivo usuarios generado en el punto 5 parte B del tp1 y utilizarlo en un script que permita simular dar de alta un usuario en términos de: usu01:x:uid:guid: :/home/usu01:/bin/bash (línea que debe agregar al archivo usuarios) El usuario usu01 debe ser pasado como argumento 

dir_tp1=$HOME/practicas/tp1
dir_tp2=$HOME/practicas/tp2

if [ $# -ne 1 -o -z $1 ]; then
	echo "Error: Ingrese el nombre del usuario a cargar"
	exit 1
fi

usuario=$1

if [ ! -f $dir_tp2/usuarios-copy ]; then
	cp $dir_tp1/usuarios usuarios-copy
fi

# read -rp "Ingrese el usuario:" usuario

# Este algoritmo busca el numero mas alto de los 1000 para devolver uno mas alto
uid=$(cat usuarios-copy | awk -F ":" 'BEGIN {max_num=0} /^.*:x:1...:/ {if($3 > max_num){max_num=$3}} END {print ++max_num}')

gid=$(cat usuarios-copy | awk -F ":" 'BEGIN {max_num=0} /^.*:x:*:1...:/ {if($3 > max_num){max_num=$3}} END {print ++max_num}')

echo "$usuario:x:$uid:$gid::/home/$usuario:/bin/bash" >> $dir_tp2/usuarios-copy
