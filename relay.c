#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_barrier_t start_barrier; //barrier to start race
pthread_cond_t start_T1RB_cv, start_T2RB_cv; //signals to start racer B
pthread_mutex_t mutex_start_T1RB, mutex_start_T2RB, winner_mutex;

int winner = 0;
void * function1();
void * function2();
void * function3();
void * function4();

int main() {
  pthread_t thread_id_T1RA, thread_id_T1RB, thread_id_T2RA, thread_id_T2RB;
  pthread_attr_t attr;
  int ret;
  void *res;
  //init mutex and condition var
  pthread_mutex_init(&mutex_start_T1RB, NULL);
  pthread_mutex_init(&mutex_start_T2RB, NULL);
  pthread_cond_init(&start_T1RB_cv, NULL);
  pthread_cond_init(&start_T2RB_cv, NULL);
  pthread_barrier_init(&start_barrier, NULL, 2);

  ret=pthread_create(&thread_id_T1RA, NULL, function1, NULL);
  if(ret!=0){
    printf("Unable to create thread1");
  }
  ret=pthread_create(&thread_id_T2RA, NULL, function2, NULL);
  if(ret!=0){
    printf("Unable to create thread2");
  }
  ret=pthread_create(&thread_id_T1RB, NULL, function3, NULL);
  if(ret!=0){
    printf("Unable to create thread3");
  }
  ret=pthread_create(&thread_id_T2RB, NULL, function4, NULL);
  if(ret!=0){
    printf("Unable to create thread4");
  }
  printf("\n Created threads \n");
  pthread_join(thread_id_T1RA, NULL);
  pthread_join(thread_id_T2RA, NULL);
  pthread_join(thread_id_T1RB, NULL);
  pthread_join(thread_id_T2RB, NULL);

  pthread_barrier_destroy(&start_barrier);
}

void * function1(){
  pthread_barrier_wait(&start_barrier); //waits to start running
  printf("arranca T1RA \n");
  for(int i=0; i<0Xffffffff; i++);
  pthread_cond_signal(&start_T1RB_cv); //delivers token
}
void * function2(){
  pthread_barrier_wait(&start_barrier); //waits to start running
  printf("arranca T2RA \n");
  for(int i=0; i<0Xffffffff; i++);
  pthread_cond_signal(&start_T2RB_cv); //delivers token
}
void * function3(){
  pthread_mutex_lock(&mutex_start_T1RB);
  pthread_cond_wait(&start_T1RB_cv, &mutex_start_T1RB);
  printf("esperando el token de T1RA \n");
  pthread_mutex_unlock(&mutex_start_T1RB);
  for(int i=0; i<0Xffffffff; i++);
  pthread_mutex_lock(&winner_mutex);
  if (winner==0){
    winner=1;
    printf("Team1 is winner \n");
  }
  pthread_mutex_unlock(&winner_mutex);
  printf("termina T1 \n");
}

void * function4(){
  pthread_mutex_lock(&mutex_start_T2RB);
  pthread_cond_wait(&start_T2RB_cv, &mutex_start_T2RB);
  printf("esperando el token de T2RA \n");
  pthread_mutex_unlock(&mutex_start_T2RB);
  for(int i=0; i<0Xffffffff; i++);
  pthread_mutex_lock(&winner_mutex);
  if (winner==0){
    winner=1;
    printf("Team2 is winner \n");
  }
  pthread_mutex_unlock(&winner_mutex);
  printf("termina T1 \n");
}
