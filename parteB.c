// Andrés Sánchez A00819118

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_sum(void *arg);
void *thread_product(void *arg);
void *thread_final(void *arg);

int A[4][4] = {
  {1, 2, 3, 4},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15}
};

int sumaAA[4][4], ppA[4][4], restaA[4][4];

int main(){
	int res;
	pthread_t sum_t,product_t,resta_t;
  	void *thread_result;

  	res = pthread_create(&sum_t, NULL, thread_sum, (void *)thread_result);
	if(res!=0){
		perror("Thread creation failed");
   	exit(EXIT_FAILURE);
	}

	res = pthread_create(&product_t, NULL, thread_product, (void *)thread_result);
	if(res!=0){
		perror("Thread creation failed");
   	exit(EXIT_FAILURE);
	}

	res = pthread_join(sum_t, &thread_result);
	res = pthread_join(product_t, &thread_result);
	if(res!=0){
		perror("Thread join failed");
   	exit(EXIT_FAILURE);
	}

	res = pthread_create(&resta_t, NULL, thread_final, (void *)thread_result);
	if(res!=0){
		perror("Thread creation failed");
   	exit(EXIT_FAILURE);
	}
	res = pthread_join(resta_t, &thread_result);
	printf("Resultado: \n");
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf(" %i ", restaA[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void *thread_sum(void *arg){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			sumaAA[i][j] = A[i][j]+A[i][j];
		}
	}
}

void *thread_product(void *arg){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			ppA[i][j] = 0;
			for(int k=0; k<4; k++){
				ppA[i][j] += A[i][k] * A[k][j];
			}
		}
	}
}

void *thread_final(void *arg){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			restaA[i][j] = ppA[i][j]-sumaAA[i][j];
		}
	}
}