// Existen varias estructuras de c
// struct permite tener varias variables relacionadas
//
// union las variables comparten la misma direccion de memoria, por lo tanto se pisan entre si. No es muy utilizado salvo para sistemas embebidos que tienen muy poca memoria
//
// enum permite tener una coleccion de identificacores mapeados a numeros. 
//

#include <stdio.h>

// declaro aca arriba son variables globales

// struct global

struct Empleado{
	int id;
	char nombre[30];
	char apellido[30];
};

// union global

union auxiliar{
	int entero;
	float flotante;
};

// enum globl 

int main (){



}
