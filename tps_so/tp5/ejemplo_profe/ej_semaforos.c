#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100000

// EL profesor pone static pero no es necesario porque esta todo en el mismo
// archivo
void *funcion_hilo1(void *arg);
void *funcion_hilo2(void *arg);

int contador = 0;

sem_t semaforo;

void *funcion_hilo1(void *arg) {

        sem_wait(&semaforo); // Comentar para ver el error
        for (int i; i < N; i++) {

                puts("Suma");
                ++contador;
        }
        sem_post(&semaforo); // Comentar para ver el error

        pthread_exit(0);
}

void *funcion_hilo2(void *arg) {

        sem_wait(&semaforo); // Comentar para ver el error
        for (int i; i < N; i++) {
                puts("Resta");
                --contador;
        }
        sem_post(&semaforo); // Comentar para ver el error

        pthread_exit(0);
}

int main(void) {

        sem_init(&semaforo, 0, 1); // Comentar para ver el error
        pthread_t hilo1, hilo2;
        pthread_create(&hilo1, NULL, funcion_hilo1, NULL);
        pthread_create(&hilo2, NULL, funcion_hilo2, NULL);

        pthread_join(hilo1, NULL);
        pthread_join(hilo2, NULL);

        printf("Contador: %d\n", contador);
        sem_destroy(&semaforo); // Comentar para ver el error
        return 0;
}
