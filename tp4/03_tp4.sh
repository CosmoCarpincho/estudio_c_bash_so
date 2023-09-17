#!/bin/bash
# Hacer un script que realice los siguientes pasos:
# 1- Crear un archivo de nombre process (usando comando touch). 
# 2- En el archivo process agregar todos los procesos que se están ejecutando en el sistema 
# 3- Del archivo process cortar el nombre usuario y PID y mandarlos al archivo solousu 
# 4- Comprimir y empaquetar el archivo process y solousu como proc-usu.tar.gz

CARPETA_CONTENEDORA=bash_archivos
RUTA_PROCESS=$CARPETA_CONTENEDORA/process
RUTA_SOLOUSU=$CARPETA_CONTENEDORA/solousu
RUTA_TAR_GZ=$CARPETA_CONTENEDORA/proc-usu.tar.gz


if [ ! -d $CARPETA_CONTENEDORA ]; then
  mkdir $CARPETA_CONTENEDORA
fi

if [ ! -f $RUTA_PROCESS ]; then
  touch $RUTA_PROCESS 
fi

# Tener en cuenta que ps usa varias nomenclaturas. aux es de bsd
ps aux > $RUTA_PROCESS 

awk '{print "Usuario:", $1, " ==>  PID:", $2}' $RUTA_PROCESS > $RUTA_SOLOUSU 

#Comprimir
tar -cvzf $RUTA_TAR_GZ $RUTA_PROCESS $RUTA_SOLOUSU

# c crear nuevo archivo .tar, v descripción detallada, z para gzip, f nombre del archivo (Siempre al final)

# Descomprimir
# tar -xvf [archivo a descomprimir] [-C] [si se quiere ubicar en otra ruta]