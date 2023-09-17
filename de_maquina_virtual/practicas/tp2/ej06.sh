#!/bin/bash
#
#6. 6. Hacer un scripts que realice los siguientes pasos: 
#+ Descomprimir el directorio tp1 de la práctica 1 en un directorio llamado nuevo 
#+ Del archivo hist.txt sacar las líneas que corresponden al comando ls y guardarlas en el archivo “listado” 
#+ Comprimir el archivo “listado” 

if [ ! -f $HOME/practicas/tp1.tar.gz ]; then
	echo "No existe el comprimido tp1.tar.gz"
	exit 1
fi

if [ ! -d $HOME/practicas/tp2/nuevo ]; then
	mkdir $HOME/practicas/tp2/nuevo
else
	rm -r $HOME/practicas/tp2/nuevo/*
fi	

#+ Descomprimir el directorio tp1 de la práctica 1 en un directorio llamado nuevo 

tar -xvzf $HOME/practicas/tp1.tar.gz -C nuevo/

#+ Del archivo hist.txt sacar las líneas que corresponden al comando ls y guardarlas en el archivo “listado” 

cat $HOME/practicas/tp2/nuevo/*/hist.txt | grep 'ls' > $HOME/practicas/tp2/listado

#+ Comprimir el archivo “listado” 

tar -cvzf $HOME/practicas/tp2/listado.tar.gz $HOME/practicas/tp2/listado
