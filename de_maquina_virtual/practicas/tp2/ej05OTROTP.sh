#!/bin/bash

usuario=$1

shellusuario=$(grep "^$usuario" /etc/passwd | cut -d ":" -f 7)  

if [[ $shellusuario =~ "bash" ]] ; then
	echo "El usuario tiene bash"
else
	echo "El usuario no tiene bash. La terminal que usa es:" $shellusuario
fi



