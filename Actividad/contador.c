//contador.c
//author: Alex Parra
//email aparra@itesm.mx
//Descripcion: Este es un programa sencillo el cual se usa para medir el tiempo que lleva contador el entero mÃ¡s grande alojado en un entero
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <limits.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex; /* protects both work_area and time_to_exit */
int micontador = 0;

int main(){
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0) {
			perror("Mutex initialization failed");
			exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
	}

	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
			perror("Thread join failed");
			exit(EXIT_FAILURE);
	}
	printf("Thread joined");

	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);

		for (micontador; micontador < INT_MAX; micontador ++);
		printf( "INT_MAX = %d y contador = %d \n",INT_MAX, micontador);

    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
