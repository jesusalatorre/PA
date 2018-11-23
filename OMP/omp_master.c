/* compile on optlab1 using
      icc -openmp testomp2.c
   and run a few times (./a.out) too see different results */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main () 
{
int i,j,k,tid,max_threads;
j=0;
printf("This is a sample of OpenMP directives.\n");
printf("For more information consult the documentation.\n\n");
#pragma omp parallel private(i,tid,max_threads) shared(j,k)
{

/* start with omp master construct -- this is the way to make sure that part 
   of the code is run sequentially only on a single CPU (master thread) */
#pragma omp master
{        
        printf("From now on, every line of the subsquent code\n");
        printf("is executed on each thread (CPU),\n");
        printf("unless instructed otherwise, so\n");
}

/* the next printf will be executed by all the threads,
   note that these might interlace with the execution above by the master */
        printf("BE CAREFULL!\n"); 
        
#pragma omp barrier /*omp barrier synchronizes the threads, that is nothing will happen until this
line in the code is reached by all the threads, after that the program will continue*/

/* next is almost the same as omp master, but anyone can execute this part; will be processed only once */
#pragma omp single
{
        max_threads=omp_get_max_threads();
        printf("We have %d threads running at max.\n", max_threads);
        printf("Press enter to continue.\n");
        getchar();/*we use getchar() to serve as a synchonization point for all the threads */
}
#pragma omp barrier
/* pragma omp critical insures the opretaions are executed by one thread at a time, 
   note that this is different from omp single/master, since the line will be processed 
   max_num_threads times*/
#pragma omp critical
        j++;
#pragma omp barrier
#pragma omp single        
{
        printf("Recall j is shared, this should give\n");
        printf("the correct result for j to be 4: j=%d\n\n",j);
}
#pragma omp barrier
        j=0;
#pragma omp barrier
        j++;/*now try the same operation w/o omp critical, you might still expect to see j==4
              at the end, see if you do*/
#pragma omp barrier
#pragma omp single
        printf("Now constrast this with no omp critical: j=%d\n\n",j);

#pragma omp barrier/*again, synchronize*/
#pragma omp single
{
        printf("Next we illustrate two work sharing constructs,\n");
        printf("startng with omp sections.\n\n");
        printf("Yoda says:\n");
}
#pragma omp barrier
/* omp sections instructs the machine to execute each section by one thread only, in any order */
/* note that the first section, printf("this line is (by thread %d)\n",tid), need to be marked */
#pragma omp sections
{
        {
  		 tid=omp_get_thread_num();
         printf("this line is (by thread %d)\n",tid);/*each of this sections will be executed by one
                                                      thread (CPU) at a time*/
        }
#pragma omp section
        {
  		 tid=omp_get_thread_num();
         printf("executed by (by thread %d)\n",tid);
        }
#pragma omp section
        {
  		 tid=omp_get_thread_num();
         printf("only one thread (by thread %d)\n",tid);
        }
}

#pragma omp barrier
#pragma omp single
{
        printf("\nNext consider omp for:\n");
        j=0;
        k=0;
}

#pragma omp barrier
/* a special directive omp for is used to split up the loops, not that i has to be private */
/* you might compare this with for loop w/o omp for directive, as in class */
#pragma omp for /* by default, threads synchronize at the end of the loop, so no need for omp barrier there */
        for(i=0;i<4;i++) 
	    {
		 j++;/*this line may be executed by any thread at any time, expect mess*/
		 #pragma omp critical
         k++;/*this line is executed by a thread at a time*/
		 tid=omp_get_thread_num();
		 printf("i:%d, thread %d, j:%d, k:%d (all at print time, might be confusing)\n",i,tid,j,k);
	    }
#pragma omp single
{
        printf("Final j might not be 4,\n");
        printf("since no omp critical was used: j=%d,\n",j);
        printf("while k must be 4: k=%d,\n",k);
        printf("and, finally, i can be any from 0 to 3: i=%d\n",i);
}

}

return 0;
}

