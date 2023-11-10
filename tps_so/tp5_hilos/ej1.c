// 2 hilos
// "Primero aprendo lenguaje C" (hilo 1)
// "Segundo tratare de aprende Sémaforos" (hilo2)
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t sem;
pthread_t hilo1, hilo2;

void *f1(void *arg) {
  sem_post(&sem);
  //Seccion critica
  printf("Primero aprendo lenguaje C\n");

  void *a = "1";
  return NULL;
}

void *f2(void *arg) {

  sem_wait(&sem);
  //Seccion critica
  puts("Segundo tratare de aprender Semaforos");

  return NULL;
}

int main(void) {
  sem_init(&sem, 0, 0);

  pthread_create(&hilo1, NULL, f1, NULL);
  pthread_create(&hilo2, NULL, f2, NULL);

  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  sem_destroy(&sem);

  return 0;
}
