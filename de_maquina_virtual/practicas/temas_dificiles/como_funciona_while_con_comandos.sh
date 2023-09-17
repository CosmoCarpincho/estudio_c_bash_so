#!/bin/bash
#Hay que entender que el while ejecuta un comando y ve su respuesta.
# Si devuelve 0 entra en el while si devuelve otro numero finaliza el while
# Tener en cuenta que [ condicion ] en el fondo es un comando
#
# Aca para demostrarlo lo que hago es crear una funcion que  despues de unas iteraciones devuelve 1
#
cont=0

funcion(){
        if [ $cont -gt 3 ]; then
                return 1
        fi

        ((++cont))
return 0
}

# generalmente lo unico que usamos es el read
# while IFS=" " read -r linea 
# EL IFS significa : Internal Field Separator. Variable de entorno que indica en que se separar los argumentos

while funcion
do
        echo $cont
done 


# while IFS=" " read -r linea
# do
# 	echo $linea
# done < /etc/passwd




