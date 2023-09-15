Precicion de float 7 numeros. Como esta en notacion cientifica seria 1erdigito,...6 decimales
Precision de double 15 num. 1erdig, ... 14 decimales

Los dos se leen con %f en printf pero si pedis mas decimales de lo que el dato tiene te devuelve mas numeros erroneos.

En el printf el float se conviernte en double pero en scanf no OJO. 

printf devuelve un numero que representa la cantidad de caracteres impresos contando los caracteres de las variables. 

fgets agrega un \n al final de la linea OJO.
