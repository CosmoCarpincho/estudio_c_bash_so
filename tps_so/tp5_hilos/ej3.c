// 2 hilos lanzados en pararelo
// semaforo que garantice exclusión mutua


#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem;
pthread_t hilo1,hilo2;
int recurso_critico = 10;

void *f1(void *arg){

	sem_wait(&sem);
	puts("f1");
	recurso_critico++;
	puts("fin f1");
	sem_post(&sem);
}

void *f2(void *arg){
	sem_wait(&sem);
	puts("f2");
	recurso_critico--;
	puts("fin f2");
	sem_post(&sem);
}

int main(){

	sem_init(&sem, 0, 1);

	pthread_create(&hilo1, NULL, f1, NULL);
	pthread_create(&hilo2, NULL, f2, NULL);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);

	printf("Recurso critico deberia ser 10 => %d\n", recurso_critico);


	return 0;
}
