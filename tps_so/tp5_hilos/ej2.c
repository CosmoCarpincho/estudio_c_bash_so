//
//
//
//
//
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define N 1000

void * aumenta(void *arg);
void * resta(void *arg);

int contador;
sem_t sem;
pthread_t hilo1,hilo2;

void * aumenta(void *arg){
	for (int i = 0 ; i < N; i++){
		sem_wait(&sem);
		// Seccion critica
		puts("Suma");
		contador++;
		sem_post(&sem);
	
	}
}

void * resta(void *arg){
	for (int i = 0 ; i < N; i++){
		sem_wait(&sem);
		// Seccion critica
		puts("Resta");
		contador--;
		sem_post(&sem);
	}
}

int main(){

	sem_init(&sem,0,1);

	pthread_create(&hilo1, NULL, aumenta, NULL);
	pthread_create(&hilo2, NULL, resta, NULL);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);

	sem_destroy(&sem);

	printf("El contador tiene que quedar en 0.\nValor: %d\n",contador);

	return 0;
}
