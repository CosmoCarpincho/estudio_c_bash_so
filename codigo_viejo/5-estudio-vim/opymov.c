#include <stdio.h>

int main (void){
	printf("Operadores y movimiento:\n");
	printf("El operador d es delete o eliminar, se puede combinar con los operadores de movimiento como dw dw db ..etc ");
	printf("Se pueden agregar numeros para repetir la operacion, es un multplicador de la cantidad de veces que se quiere hace el operador. Eje presionar 6 veces dw es equivalente a poner d6w\n");
	printf("Cuando eliminamos en vim queda grabado siempre en el clipboard\n despues se puede pegar con p. Pega en la linea debajo del cursor y si queres pegar en la linea de arriba P\n cw change word borra desde donde tengas el cursor hasta finalizar la palabra y te pone en modo insert para que cambies la palabra\nciw borra el objeto palabra para que la modifiques\n");
	printf("Desplazamiento:\n gg para ir arriba del archivo\nG para ir al final del archivo\n <numero>G para ir a la linea con ese numero");
	return 0;

}
