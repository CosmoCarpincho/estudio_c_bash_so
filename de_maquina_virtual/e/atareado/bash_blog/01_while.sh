#!/bin/bash

#Cree estructura while. (frase que se repite 10 veces)

i=0
while [ $i -lt 10 ]
do
	echo "frase nro:$i" 
	((i++))
done
