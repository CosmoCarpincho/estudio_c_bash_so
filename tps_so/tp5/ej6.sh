#!/bin/bash

echo "Ingrese por parametro con 0 si quiere desahibilitar la memoria swap y con 1 para habilitarlo"
read opcion

if [ $opcion -eq 0 ]; then
	swapoff -a
	echo "deshabilitado"
fi

if [ $opcion -eq 1 ]; then
	swapon -a
	echo "habilitado"
fi
