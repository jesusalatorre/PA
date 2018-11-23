/******************************************************************************
* FILE: omp_orphan.c
* DESCRIPTION:
*   OpenMP Example - Parallel region with an orphaned directive - C/C++ Version
*   This example demonstrates a dot product  being performed by an orphaned
*   loop reduction construct.  Scoping of the reduction variable is critical.
* AUTHOR: Blaise Barney  5/99
* LAST REVISED: 06/30/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/*#define VECLEN 100*/




int main (int argc, char *argv[]) {


 if (argc < 2) {
    printf("uso %s <tamaño> <sum2> .... <num-n>\n", argv[0]);
    exit(-1);
  }

 int i,tid, size_vector=atoi (argv[1]);
 float  a[size_vector], b[size_vector],sum;
for (i=0; i < size_vector; i++)
  a[i] = b[i] = 1.0 * (rand() % size_vector);
sum = 0.0;

for (i=0; i < size_vector; i++)
    {

    sum = sum + (a[i]*b[i]);
    printf("  tid= %d i=%d a[i]= %f b[i]= %f \n",tid,i,a[i],b[i]);
    }
  

printf("Sum = %f\n",sum);

}

