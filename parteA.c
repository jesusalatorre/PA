#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int A[4][4] = {
  {1, 2, 3, 4},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15}
};
int B[4][4] = {
  {1, 2, 3, 4},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15}
};
int D[4][4] = {
  {1, 2, 3, 4},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15}
};
int E[4][4] = {
  {1, 2, 3, 4},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15}
};

int C[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void *thread_function0(void *arg);
void *thread_function1(void *arg);
void *thread_function2(void *arg);
void *thread_function3(void *arg);

int main(){

  int res;
  pthread_t a_thread;
  void *thread_result;
  //Hilo0
  res = pthread_create(&a_thread, NULL, thread_function0, (void *)thread_result);
  if (res != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
  res = pthread_join(a_thread, &thread_result);
  if (res != 0) {
      perror("Thread join failed");
      exit(EXIT_FAILURE);
  }

  //Hilo1
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

  //Hilo2
  res = pthread_create(&a_thread, NULL, thread_function2, (void *)thread_result);
  if (res != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
  res = pthread_join(a_thread, &thread_result);
  if (res != 0) {
      perror("Thread join failed");
      exit(EXIT_FAILURE);
  }

  //Hilo3
  res = pthread_create(&a_thread, NULL, thread_function3, (void *)thread_result);
  if (res != 0) {
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
  res = pthread_join(a_thread, &thread_result);
  if (res != 0) {
      perror("Thread join failed");
      exit(EXIT_FAILURE);
  }

  printf("Resultado:");
  for(int i=0; i<4; i++){
    printf("\n");
    for(int j=0; j<4; j++){
      printf(" %i ", C[i][j]);
    }
  }
  printf("\n");
}

void *thread_function0(void *arg){
  for(int j=0; j<4; j++){
    for(int k=0; k<4; k++){
      C[0][j]+=(A[0][k]*B[k][j]);
    }
    C[0][j]-=(D[0][j]+E[0][j]);
  }
}

void *thread_function1(void *arg){
  for(int j=0; j<4; j++){
    for(int k=0; k<4; k++){
      C[1][j]+=(A[1][k]*B[k][j]);
    }
    C[1][j]-=(D[1][j]+E[1][j]);
  }
}

void *thread_function2(void *arg){
  for(int j=0; j<4; j++){
    for(int k=0; k<4; k++){
      C[2][j]+=(A[2][k]*B[k][j]);
    }
    C[2][j]-=(D[2][j]+E[2][j]);
  }
}

void *thread_function3(void *arg){
  for(int j=0; j<4; j++){
    for(int k=0; k<4; k++){
      C[3][j]+=(A[3][k]*B[k][j]);
    }
    C[3][j]-=(D[3][j]+E[3][j]);
  }
}
