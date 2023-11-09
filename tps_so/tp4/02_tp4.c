/* 2. Realizar una rutina en lenguaje C que pida cargar un vector de 10
elementos numéricos y los devuelva ordenado de menor a mayor.
*/

#include <stdio.h>

void ordenar_vector(int *vector, int tam_vector) {

  int aux;
  for (size_t i = 0; i < tam_vector - 1; i++) {
    for (size_t j = i + 1; j < tam_vector; j++) {
      if (vector[j] < vector[i]) {
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }
}

int main() {
  int vector[10];

  printf("Ingrese 10 numeros para cargar al vector\n");
  for (int i = 0; i < 10; i++) {
    printf("Posición %d:", i + 1);
    scanf("%d", &vector[i]);
  }

  int tam_vector = sizeof(vector) / sizeof(vector[0]);

  printf("\nVector => ");
  for (size_t j = 0; j < tam_vector; j++) {
    printf("%d ", vector[j]);
  }

  ordenar_vector(vector, tam_vector);

  printf("\nVector ordenado de menor a mayor => ");
  for (size_t j = 0; j < tam_vector; j++) {
    printf("%d ", vector[j]);
  }

  printf("\n");

  return 0;
}
