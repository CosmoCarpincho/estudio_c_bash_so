#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
  // Crear punter

  typedef struct empleado {
    char nombre[20];
    unsigned ind;
  } Empleado;

  int valor = 45;
  __int64 nn = 64;
  int n2 = 32;

  long long m1 = sizeof(nn);
  long long m2 = sizeof(n2);

  Empleado empleado;
  empleado.ind = 10;
  strcpy(empleado.nombre, "Pepe");

  int* puntero;
  Empleado* punteroEmp;

  puntero = &valor;

  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  puntero = &array[2];
  puntero = array;

  unsigned num = sizeof(int);
  punteroEmp = &empleado;

  printf("El nombre del empleado es: %s , %s", punteroEmp->nombre,
         empleado.nombre);

  return 0;
}
