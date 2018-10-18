//contador.c
//author: Alex Parra
//email aparra@itesm.mx
//Descripcion: Este es un programa sencillo el cual se usa para medir el tiempo que lleva contador el entero mÃ¡s grande alojado en un entero
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>

void *thread_function(void *arg);
sem_t bin_sem;
int micontador = 0;

int main(){
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
			perror("Thread join failed");
			exit(EXIT_FAILURE);
	}
	res = sem_init(&bin_sem, 0, 0);
	if (res != 0) {
		perror("Semaphore initialization failed");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
		while(micontador < INT_MAX){
			micontador++;
    }
		printf( "INT_MAX = %d y contador = %d \n",INT_MAX, micontador);
    pthread_exit(NULL);
}
