#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_barrier_t start_barrier;
pthread_cond_t start_T1RB, start_T2RB;
pthread_mutex_t mutex_start_T1RB, mutex_start_T2RB, winner_mutex;
bool winner = false;
void *function_T1RA();
void *function_T1RB();
void *function_T2RA();
void *function_T2RB();

int main() {
	pthread_t thread_T1RA;
	pthread_t thread_T1RB;
	pthread_t thread_T2RA;
	pthread_t thread_T2RB;
	pthread_attr_t attr;
	int ret;
	void *res;

	pthread_mutex_init(&mutex_start_T1RB, NULL);
	pthread_mutex_init(&mutex_start_T2RB, NULL);
	pthread_cond_init(&start_T1RB, NULL);
	pthread_cond_init(&start_T2RB, NULL);
	pthread_barrier_init(&start_barrier, NULL, 2);

	ret = pthread_create(&thread_T1RA, NULL, function_T1RA, NULL);
	if(ret != 0) {
		printf("Unable to create thread T1RA\n");
	}
	ret = pthread_create(&thread_T2RA, NULL, function_T2RA, NULL);
	if(ret != 0) {
		printf("Unable to create thread T2RA\n");
	}
	ret = pthread_create(&thread_T1RB, NULL, function_T1RB, NULL);
	if(ret != 0) {
		printf("Unable to create thread T1RB\n");
	}
	ret = pthread_create(&thread_T2RB, NULL, function_T2RB, NULL);
	if(ret != 0) {
		printf("Unable to create thread T2RB\n");
	}

	printf("Threads created\n");
	pthread_join(thread_T1RA, NULL);
	pthread_join(thread_T2RA, NULL);
	pthread_join(thread_T1RB, NULL);
	pthread_join(thread_T2RB, NULL);

	pthread_barrier_destroy(&start_barrier);
}

void *function_T1RA() {
	pthread_barrier_wait(&start_barrier);
	printf("arranca T1RA\n");
	for(int i = 0; i < 0xffffff; i++);
	pthread_cond_signal(&start_T1RB);
}

void *function_T2RA() {
	pthread_barrier_wait(&start_barrier);
	printf("arranca T2RA\n");
	for(int i = 0; i < 0xffffff; i++);
	pthread_cond_signal(&start_T2RB);
}

void *function_T1RB() {
	pthread_mutex_lock(&mutex_start_T1RB);
	pthread_cond_wait(&start_T1RB, &mutex_start_T1RB);
	printf("empezando el token de T1RB\n");
	pthread_mutex_unlock(&mutex_start_T1RB);
	for(int i = 0; i < 0xffff; i++);
	pthread_mutex_lock(&winner_mutex);
	if(!winner) {
		winner = true;
		printf("team 1 is the winner\n");
	}
	pthread_mutex_unlock(&winner_mutex);
	printf("termina T1\n");
}

void *function_T2RB() {
	pthread_mutex_lock(&mutex_start_T2RB);
	pthread_cond_wait(&start_T2RB, &mutex_start_T2RB);
	printf("empezando el token de T2RB\n");
	pthread_mutex_unlock(&mutex_start_T2RB);
	for(int i = 0; i < 0xffff; i++);
	pthread_mutex_lock(&winner_mutex);
	if(!winner) {
		winner = true;
		printf("team 2 is the winner\n");
	}
	pthread_mutex_unlock(&winner_mutex);
	printf("termina T2\n");
}
