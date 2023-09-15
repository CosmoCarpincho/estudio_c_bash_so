#include <stdio.h>

int main(){
	int n1 = 10;
	printf("Direccion de &n1 %p\n", &n1);
	miFuncion(&n1);
	return 0;
}

void miFuncion(int *num1){
	printf("Direccion de puntero-num1:%p\n",num1);
	printf("Valor de *num1 %i\n", *num1);
	printf("Direccion de &n1 %p\n", &num1);

}
