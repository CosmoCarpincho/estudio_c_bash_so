# 4. Crear un script al cual se le pase como argumento un nombre de usuario
# y muestre los procesos que está ejecutando ese usuario.
# En caso de que no se pase ningún argumento, debe mostrar todos los procesos en ejecución,
# y en caso de que el usuario pasado como argumento sea root, mostrar un mensaje de error

usuario=$1
if [ $# -eq 0 ]; then
	ps aux
elif [[ $# -eq 1 && $usuario =~ [Rr][Oo][Oo][Tt] ]]; then
	echo "ERROR: no se permite usuario root"
	exit 1
elif [ $# -eq 1 ]; then
	ps -fu $usuario 2>/dev/null || echo "El usuario [$usuario] no existe o no esta ejecutando procesos"
else
	echo "Ingrese un usuario como argumento o ninguno para ver todos los procesos"
	exit 1
fi

# ps -fu $usuario 2> /dev/null # Si el usuario no existe elimino el error y agrego comentario abajo

# if [ $? -ne 0 ]; then
#   echo "El usuario: $usuario no existe"
# fi

# ps -fu $usuario 2> /dev/null || echo "El usuario [$usuario] no existe" # forma corta
