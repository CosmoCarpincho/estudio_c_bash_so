#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NR_LOOP 10000

static void * thread_1_function(void* arg);
static void * thread_2_function(void* arg);

static int counter = 0;

sem_t sem1;

int main(){


	pthread_t thread_1, thread_2;
	pthread_create(&thread_1, NULL, *thread_1_function, NULL);
	pthread_create(&thread_2, NULL, *thread_2_function, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	printf("valor counter %d", counter);

	return 0;
}

static void * thread_1_function(void* arg){

	for(int i = 0; i < NR_LOOP; i++)
	{
		counter +=1;
	}

	return 0;
}

static void * thread_2_function(void* arg){

	for(int i = 0; i < NR_LOOP; i++)
	{
		counter -=1;
	}

	return 0;
}