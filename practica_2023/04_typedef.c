#include <stdio.h>

int main() {
  // typedef sirve para definir tipos de datos de otros
  // entero es un nuevo tipo de dato creado a partir de int
  // typedef <de> <nuevo>
  typedef int entero;

  entero n1, n2;

  n1 = 10;
  n2 = 20;

  n2 += n1;

  printf("Numero: %d\n", n2);

  // Se usa para definir tipos de datos formados por structs.
  // En el kernel no se usa porque dificulta la lectura ya que no se sabe el
  // tipo de dato.

  typedef struct persona {
    char nombre[30];
    char apellido[30];

  } persona;

  persona p = {.nombre = "Cosmo", .apellido = "Carpincho"};

  printf("%s %s \n", p.nombre, p.apellido);
  return 0;
}