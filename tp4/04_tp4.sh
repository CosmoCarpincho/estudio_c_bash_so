# 4. Crear un script al cual se le pase como argumento un nombre de usuario
# y muestre los procesos que está ejecutando ese usuario.
# En caso de que no se pase ningún argumento, debe mostrar todos los procesos en ejecución,
# y en caso de que el usuario pasado como argumento sea root, mostrar un mensaje de error

usuario=$1

if [ $# -ne 1 ]; then
  echo "Debe ingresar como argumento el nombre del usuario."
  exit 1
fi

if [[ $1 =~ [Rr][Oo][Oo][Tt] ]];then
  echo "ERROR: no se permite usuario root"
  exit 1
fi

# ps -fu $usuario 2> /dev/null # Si el usuario no existe elimino el error y agrego comentario abajo

# if [ $? -ne 0 ]; then
#   echo "El usuario: $usuario no existe"
# fi

ps -fu $usuario 2> /dev/null || echo "El usuario [$usuario] no existe" # forma corta