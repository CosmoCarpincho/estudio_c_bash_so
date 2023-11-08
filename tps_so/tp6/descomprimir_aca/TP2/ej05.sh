#!/bin/bash

# 5. Hacer un script que indique la cantidad de archivos y directorios que hay en un directiorio cualquiera pasado como argumento, usando estructuras repetitivas

# Argumentos
dir=$1

# Validaciones
if [ $# -ne 1 -o ! -d $1 ]; then
	echo "Ingrese un directorio"
	exit 1
fi


#Forma con find
echo  "forma con find =>"

codigo='cant=0; for elemento; do ((++cant)); done; echo $cant'

echo -n "La cantidad de archivos en $dir es: " 
find $dir -maxdepth 1 -type f -exec bash -c '
cant_file=0; for archivo; do ((++cant_file)); done; echo $cant_file ' nom_script {} +
# Es curioso que si pongo el salto de linea despues de ' funciona.

echo -n "La cantidad de directorios en $dir es: "
find $dir -maxdepth 1 -mindepth 1 -type d -exec bash -c "$codigo" nom_script {} +
#Aca probe pasar el codigo como variable
#
#IMPORTANTE: bash -c "codigo" <argumentos> ... en los argumentos tiene que ir el nombre del script. Digamos el $0. OJOO. sino te itera una vez menos ya que toma el primer resultado de find como nombre
#
#el find toma el directorio que le pasaste como parametro. Para no tenerlo en cuenta poner -mindepth 1
#


# Forma con iteraccion
echo -e "\n      ======\n"
echo  "forma con interacion =>"

cant_dir='0'
cant_fil='0'

for elemento in "$dir"/* ; do

	elemento=$(tr -s '/' <<< $elemento)

	if [ -f $elemento ]; then
		((++cant_fil))
	fi

	if [ -d $elemento ]; then
		((++cant_dir))
	fi
done

echo "Cantidad de archivos en $dir es: $cant_fil"
echo "Cantidad de directorios en $dir es: $cant_dir"
