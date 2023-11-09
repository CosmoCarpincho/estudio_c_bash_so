// Compilar con -lpthread
#include <pthread.h>
#include <stdio.h>

// Un puntero void es un puntero a cualquier cosa

void *func_hilo(void *arg) {
  printf("Soy un hilo\n");
  pthread_exit(0);
}

int main(void) {

  pthread_t hilo;
  pthread_create(&hilo, NULL, func_hilo, NULL);
  // puntero hilo, atributos hilo, funcion/rutina que ejecuta, argumentos

  // Pongo varios para que en algun momento cambie el orden y se muestre que se
  // necesitan semaforos
  printf("Este es el hilo principal\n");
  printf("Este es el hilo principal\n");
  printf("Este es el hilo principal\n");
  printf("Este es el hilo principal\n");
  printf("Este es el hilo principal\n");

  // para ejecutar el hilo
  // hilo, retorno del hilo
  pthread_join(hilo, NULL);

  return 0;
}
