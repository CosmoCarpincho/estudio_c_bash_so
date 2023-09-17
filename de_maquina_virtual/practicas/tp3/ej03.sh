#!/bin/bash
# 3- Recorrer el directorio …/practicas/TP1 y encontrar los archivos ordinarios que tengan permiso igual a 644. De dichos archivos guardar solo los nombres en un archivo de nombre “perm644”. 

dir_tp1=$HOME/practicas/tp1

find $dir_tp1 -type f -perm 644 -printf "%f\n"> perm644
