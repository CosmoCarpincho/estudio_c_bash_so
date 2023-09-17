#!/bin/bash
#Extra: Video while y until. Arme un menu con while y con until de 4 items y con apretar s se salga.
#¿Por qué al apretar espacio, enter, tab puede romper la condición y como solucionarlo?

#opcion=1 #para que entre en el while
#while [ "$opcion" = "1" ] || [ "$opcion" = "2" ] || [ "$opcion" = "3" ] || [ "$opcion" = "4" ]
until [ "$opcion" = "s" ] || [ "$opcion" = "S" ]
do

clear
echo
echo "Seleccione la opcion deseada"
echo
echo "1. Mostrar directorio actual"
echo
echo "2. Crear directorio"
echo
echo "3. Borrar directorio"
echo 
echo "4. Renombrar directorio"
echo
echo "S. Salir"
echo
read -n 1 -p "Intruduzca el numero de opcione: " opcion
echo
read -n 1 -p "Pulse una tecla para continuar" tecla
done
