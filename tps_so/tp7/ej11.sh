#!/bin/bash

if [ ! -d edirectory ]; then
	mkdir edirectory
fi

if [ ! -d practicas/ ]; then
	echo "No existe la carpeta practicas"
	exit 2
fi

if [ ! -d practicas/TP1 ]; then
	echo "No existe la carpeta TP1"
	exit 3
fi

if [ ! -d practicas/TP2 ]; then
	echo "No existe la carpeta TP2"
	exit 4
fi

for dir in $(find practicas -mindepth 1 -type d); do
	nombre_dir=$(basename $dir)
	# --backup=t o numbered es para que agrege un numero si se repite algun nombre de carpeta
	ln -s --backup=t $dir edirectory/$nombre_dir
done

if [ ! -d efiler ]; then
	mkdir efiler
fi

if [ ! -f practicas/TP2/ej1.sh ] && [ ! -f practicas/TP2/ej2.sh ]; then
	echo "No existen los ejercicios para hacer los enlaces"
	exit 5
else
	ln --backup=t -s practicas/TP2/ej1.sh efiler/ej1_link
	ln --backup=t -s practicas/TP2/ej2.sh efiler/ej2_link
fi
