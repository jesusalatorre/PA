#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>

#define INTMAX INT_MAX/32

float x[INTMAX];
float y[INTMAX];
float a;

void *thread_function(void *arg);
void *thread_function1(void *arg);

int main(){
  size_t n;
  srand(time(NULL));
  a = rand();
  int res;
  pthread_t a_thread;
  void *thread_result;
  res = pthread_create(&a_thread, NULL, thread_function, (void *)thread_result);
  if (res != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
  res = pthread_join(a_thread, &thread_result);
  if (res != 0) {
      perror("Thread join failed");
      exit(EXIT_FAILURE);
  }

  res = pthread_create(&a_thread, NULL, thread_function1, (void *)thread_result);
  if (res != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
  res = pthread_join(a_thread, &thread_result);
  if (res != 0) {
      perror("Thread join failed");
      exit(EXIT_FAILURE);
  }

  printf("done with SAXPY\n");
}

void *thread_function(void *arg){
  for(int count=0; count<INTMAX;count++){
    a=rand();
    y[count]=a*x[count]+y[count];
  }
}

void *thread_function1(void *arg){
  for(int count = 0; count<INTMAX; count++){
    y[count]=count;
    x[count]=count*2;
  }
}
