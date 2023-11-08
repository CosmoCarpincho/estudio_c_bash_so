#!/bin/bash
#
# 18- Hacer un scripts que al pasarle un directorio cualquiera que contenga archivos ordinarios,
# le borre a cada uno de los archivos las líneas 2 a 5, el nuevo archivo de salida se debe llamar
# igual que el original con el agregado al final del nombre “-m”, los archivos nuevos dejarlos en
# un directorio de nombre “ar-modificados”

if [ $# -ne 1 ] || [ ! -d $1 ]; then
	echo "Error:"
	echo "Ingrese un directorio"

fi

dir=$1


find $dir -type f -exec  echo {} \;:q
