#!/bin/bash

echo "Ingrese 100 para nivel de intercambio del 100%, 50 para %50 y 0 %0 "
read b
if [[ $b -eq 100 ]]; then
	sysctl vm.sappiness=100
elif [[ $b -eq 50 ]]; then
	sysctl vm.swappiness=50
else
	sysctl vm.swappiness=0
fi
