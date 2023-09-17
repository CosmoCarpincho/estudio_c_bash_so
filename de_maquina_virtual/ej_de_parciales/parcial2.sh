#!/bin/bash

# Hacer un script que visualice un menu de dos opciones:
# ** La priumera llamada "Directorio" debe pedir un directorio por consola y devolver (en caso de que exista) el tamanio del archivo que mas tamanio ocupa. Tambien se debe contabilizar la cantidad de archivos que terminen .txt
# ** La segunda llamada  "Archivo" debe pedir un archivo por consola y realizar las siguientes tareas:
# ==> Informar si el archivo es ejecutable
# ==> Informar cuantas lineas tiene
# ==> Borrar las ultimas 5 lineas del archivo y guardar la salida en un archivo llamado igual que el original con el agredado al final del nombre "-mod".


# Menu
menu(){
	op=""

	until [ $op == "3" ]; do
		echo
		echo "1) Direcorio"
		echo "2) Archivo"
		echo "3) Quit"
		echo -n "Ingrese la opcion deseada: "
		read op
		echo

		case $op in
			1)
				fn_directorio
				;;
			2)
				fn_archivo
				;;
			3|q|quit|Q|QUIT|exit|Exit|EXIT)
				echo "Programa finalizado"
				exit 0
				;;
			*)
				echo -e "Opcion ingresada incorrecta"
				;;
		esac
	
	done
}

# Funcion primer punto

 fn_directorio(){
	local dir=""
 	local max_tam_archivo=0
	local max_archivo=""
	local cant_txt=0

	echo "Directorio"
	read -rp "Ingrese un directorio: " dir # -r para que no sean de escape las \
	
	if [ ! -d $dir ]; then
		echo "No ingreso un directorio"
		return 1
	fi

	echo $dir

	for archivo in $(find "$dir" -type f); do 

		tam_archivo=$(du -b $archivo | cut -f 1)

		if [ $tam_archivo -gt $max_tam_archivo ]; then
			max_tam_archivo=$tam_archivo
			max_archivo=$archivo
		fi

		if [[ $archivo =~ (.*)\.txt ]]; then
			((++cant_txt))
		fi
	done

	echo "El archivo mas grande es: $max_archivo con un tamanio de: $max_tam_archivo"
	echo "La cantidad de archivos txt es: $cant_txt B"
 }

# Funcion del segundo punto

fn_archivo(){
	local ar=""
	read -rp "Ingrese un archivo: " ar

	if [ !  -f "$ar" ]; then
		echo "No ingreso un archivo"
		return 1
	fi

	if [ -x $ar ]; then
		echo "El archivo $ar es ejecutable"
	else
		echo "El archivo $ar no es ejecutable"
	fi

	wc -l $ar | awk '{print "Tiene", $1, "lineas"}'

	head -n -5 $ar > "$ar"-mod

}


# programa

menu

