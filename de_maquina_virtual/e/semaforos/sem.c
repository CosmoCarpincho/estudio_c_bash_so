#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

sem_t semaforo;

int main(){

	sem_init(&semaforo,1,2);

	int num_fork = fork();

	if (num_fork > 0){
		// Proceso Abuelo
		printf("Hola\n");
		sem_post(&semaforo);
	}
	else if (num_fork == 0){

		int num_fork2 = fork();

		if (num_fork2 > 0){
			// Proceso Padre
			sem_wait(&semaforo);
			printf("buen dia\n");
			sem_post(&semaforo);
			sem_post(&semaforo);

		}
		else if (num_fork2 == 0){
			// Proceso Hijo
			sem_wait(&semaforo);
			sem_wait(&semaforo);
			printf("adios\n");
		}
		else {
			printf( "Error con segundo fork\n");
		}
	}
	else {
		printf("Error el primer fork\n");
	}

}
