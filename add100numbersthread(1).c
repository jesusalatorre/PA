#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>


void *thread_add1();
void *thread_add2();
void *thread_add3();
void *thread_add4();
int tamano=INT_MAX;
int array[10000];
double sum1=0,sum2=0,sum3=0,sum4=0,sumtotal=0;

int main()
{
   int n=10000, sum = 0, c,res;
   pthread_t thread1,thread2,thread3,thread4;
 
   for (c = 0; c < n; c++)
   {
       array[c]=c;
   }
 	res = pthread_create(&thread1, NULL, thread_add1, NULL);
	res = pthread_create(&thread2, NULL, thread_add2, NULL);
	res = pthread_create(&thread3, NULL, thread_add3, NULL);
	res = pthread_create(&thread4, NULL, thread_add4, NULL);
	res = pthread_join(thread1, NULL);
	res = pthread_join(thread2, NULL);
	res = pthread_join(thread3, NULL);
	res = pthread_join(thread4, NULL);
/*   for (c = 0; c < n; c++)
   {
            sum = sum + array[c];
   }
*/
sumtotal=sum1+sum2+sum3+sum4; 
   printf("Sum = %f\n",sumtotal);
 
   return 0;
}
void *thread_add1(){
	int c=0;
	
	for (c = 0; c < 2500; c++)
	   {
		    sum1 = sum1 + array[c];
	   }
}
void *thread_add2(){
	int c=0;
	
	for (c = 2501; c < 5000; c++)
	   {
		    sum2 = sum2 + array[c];
	   }
}
void *thread_add3(){
	int c=0;
	
	for (c = 5001; c < 7500; c++)
	   {
		    sum3 = sum3 + array[c];
	   }
}
void *thread_add4(){
	int c=0;
	
	for (c = 7501; c < 9999; c++)
	   {
		    sum4 = sum4 + array[c];
	   }
}

