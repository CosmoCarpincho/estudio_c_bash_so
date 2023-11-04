/* Hacer un programa en c que permite a traves
* de 2 hilos distintos la impresión de dos mensajes.
* a) Primer mensaje 
* b) Segundo mensaje
* aplicando semaforos sincronizar que 
* se ejecute primero el b y luego el a
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

static void * funcion_hilo_1(void* arg);
static void * funcion_hilo_2(void* arg);

static void * funcion_hilo_1(void * arg){
  sem_wait(&sem);
  //sem_post(&sem);
  puts("Primero");
  //sem_post(&sem); //desbloquea

}

static void *funcion_hilo_2(void *arg){
  //sem_wait(&sem);
  
  puts("Segunda");
  sem_post(&sem);

}

int main (){

  // puntero al hilo, atributo de hilo...
  pthread_t hilo1, hilo2;
  pthread_create(&hilo1, NULL, *funcion_hilo_1, NULL);
  pthread_create(&hilo2, NULL, *funcion_hilo_2, NULL);


  //puntero al semaforo, si es compart...
  sem_init(&sem, 0, 0);

  //hilo, estado de salida...
  pthread_join(hilo2, NULL);
  pthread_join(hilo1, NULL);

  return 0;
}
