#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct

struct Cuenta {
  char nombre[30];
  char apellido[40];
  int identificador;
  int saldo;
};

struct pruebaMemoria {
  int n1;
  int n2;
};

// Error porque el struct lo tiene que recibir como parametro. Demostrado en
// nuevoPrueba. Si uso malloc funcionaria???
struct Cuenta* nuevaCuenta(char* nombre, char* apellido, int identificador,
                           int saldo) {
  // struct Cuenta nuevo = {.nombre = *nombre,
  //                        .apellido = *apellido,
  //                        .identificador = identificador,
  //                        .saldo = saldo};

  struct Cuenta* nuevo2;
  nuevo2 = (struct Cuenta*)malloc(sizeof(struct Cuenta) * 1);

  // IMPORTANTE el strcpy es inseguro porque no pide el tamaño del texto a
  // copiar.
  strcpy(nuevo2->nombre, "Cosmo");
  strcpy(nuevo2->apellido, "Carpincho");
  nuevo2->identificador = 1;
  nuevo2->saldo = 1500;

  return nuevo2;
}

// struct pruebaMemoria* nuevoPrueba(int* n1, int* n2) {
//   struct pruebaMemoria nuevo = {.n1 = 1, .n2 = 2};

//   return &nuevo;  // Da error porque la variable se destruye cuando se
//   termina
//                   // la fúncion.
// }

// ENUMS
//  Sirve para crear un conjunto de identificadores
enum dias_semana {
  LUNES,
  MARTES,
  MIERCOLES,
  JUEVES = 10,
  VIERNES,
  SABADO,
  DOMINGO
};

// UNION
union mi_union_t {
  int entero;
  float flotante;
};

int main() {
  /* Mi hipotesis: es que lo siguiente no funciona porque el puntero que recibe
   esta dentro de una función. (correcto) */

  // struct pruebaMemoria* p1 = nuevoPrueba(1, 2);
  // struct pruebaMemoria* p2 = nuevoPrueba(3, 4);

  // printf("struct p1 => n1 = %d, n2 = %d\n", p1->n1, p1->n2);
  // printf("struct p2 => n1 = %d, n2 = %d\n", p2->n1, p2->n2);

  struct Cuenta* p1 = nuevaCuenta("Cosmo", "Carpincho", 1, 15000);
  printf("%s %s %d %d \n", p1->nombre, p1->apellido, p1->identificador,
         p1->saldo);

  // ENUM
  printf("ENUMS\n");
  enum dias_semana dia;
  dia = LUNES;
  printf("%d\n", dia);
  dia = VIERNES;
  printf("%d\n", dia);
  printf("FIN ENUMS\n");

  // UNION
  // Porque solo sale el flotante?
  // Lo que sucede es que comparten la misma dirección de memoria. Se pisan. Por
  // lo tanto el ultimo asignado el el que tiene retiene el valor dejando a los
  // demascon errores El tamaño de memoria reservado es el maximo
  union mi_union_t u;
  u.entero = 1234;
  u.flotante = 4.22E5;
  u.entero = 12;
  printf("entero = %d\n", u.entero);
  printf("flotante = %f\n", u.flotante);
  printf("formato entero a flotante = %d\n", u.flotante);
  return 0;
}
