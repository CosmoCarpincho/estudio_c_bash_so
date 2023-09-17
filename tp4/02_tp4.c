/* 2. Realizar una rutina en lenguaje C que pida cargar un vector de 10
elementos numéricos y los devuelva ordenado de menor a mayor.
*/

#include <stdio.h>

int main() {
  int vector[10];

  printf("Ingrese 10 numeros para cargaral vector\n");
  for (size_t i = 0; i < 10; i++) {
    printf("Posición %d:", i + 1);
    scanf("%d", &vector[i]);
  }

  int tam_vector = sizeof(vector) / sizeof(vector[0]);

  printf("\nVector => ");
  for (size_t j = 0; j < tam_vector; j++) {
    printf("[%d]", vector[j]);
  }

  printf("\n");

  return 0;
}