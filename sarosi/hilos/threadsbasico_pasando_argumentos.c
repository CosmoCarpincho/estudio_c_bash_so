// Compilar con -lpthread
#include <pthread.h>
#include <stdio.h>

// Un puntero void es un puntero a cualquier cosa

void *func_hilo(void *arg) {
  // Primero casteamos a puntero int
  // despues pedimos el valor del puntero
  int valor_pasado_a_entero = *(int *)arg;
  printf("Soy un hilo y el valor pasado es: %d\n", valor_pasado_a_entero);
  pthread_exit(0);
}

int main(void) {

  pthread_t hilo;

  // paso argumento
  int valor = 5;
  pthread_create(&hilo, NULL, func_hilo, &valor);

  // puntero hilo, atributos hilo, funcion/rutina que ejecuta, argumentos

  printf("Este es el hilo principal\n");

  pthread_join(hilo, NULL);

  return 0;
}
