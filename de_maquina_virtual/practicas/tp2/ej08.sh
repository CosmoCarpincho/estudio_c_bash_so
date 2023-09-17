#!/bin/bash
#
#8. Implementar con un script el punto 6 de la parte B de la práctica 1
#6- En el archivo usuarios creado en el punto anterior, identificar el uid ( Identificador de usuario), gid (Ientificador de grupo), y shell (Interpetre de comandos) y guardarlos en el archivo perfil.txt creado en el punto 3 

dir_tp1=$HOME/practicas/tp1

cat $dir_tp1/usuarios | awk -F ":" '/(bash|sh)$/ {print "Usuario",$1,"uid:",$3,"gid:",$4,"shell:",$7}'  > $dir_tp1/perfil.txt 
