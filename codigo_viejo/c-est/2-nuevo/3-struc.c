#include <stdio.h>
#include <string.h>

struct cuenta {
	char nombre[30];
	char apellido[40];
	int identificador;
	int saldo;

};

void imprimir_datos (struct cuenta *c){
	printf("El cliente %s %s tiene %d euros en cuenta.\n", (*c).nombre, c->apellido, c->saldo);
}

int main() {
	struct cuenta c1;// se puede eliminar la palabra struct type def

	strcpy(c1.nombre, "Pepito"); // es una funcion insegura porque no pone limite a los caracteres que podes pasarle. El final de las cadenas de caracteres en un cero . Todos los bits ceros.
	strcpy(c1.apellido, "Peres");
	c1.identificador = 1234;
	c1.saldo = 400;
	imprimir_datos (&c1);
	return 0;
}
