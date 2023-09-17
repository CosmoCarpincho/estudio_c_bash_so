#!/bin/bash

# 9. Implementar un script usando la sentencia while, en donde se lea el archivo passwd línea por línea y se imprima el mismo por Terminal. 

while IFS=" " read -r linea
do
	echo $linea

done < /etc/passwd 

