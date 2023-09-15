#include <stdio.h>

int main (void){
	int *ptr = NULL;

	printf("valor del puntero %p", *ptr); //Como NULL no se puede acceder devuelve Segmentation fault

	return 0;
}
