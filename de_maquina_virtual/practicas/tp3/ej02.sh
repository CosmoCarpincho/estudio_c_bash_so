#!/bin/bash

#2- Implementar un script que cambie los permisos de todos los ejercicios (scripts) de la practica 2 que se encuentran en …/practicas/tp2/ para que puedan ser ejecutados por otros y modificados por el grupo, el resto de los permisos quedan igual. 

dir_tp2=$HOME/practicas/tp2

sudo chmod g+w,o+x $(find $dir_tp2 -type f)

