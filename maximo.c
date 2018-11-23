#include <stdio.h>
#include <limits.h>
#define SizeArray INT_MAX
 
int array[SizeArray];
int main()
{
    int  *minimum, size, c, location = 1;
   size=SizeArray;
    
   
    printf("Enter %d integers\n", size);
   
    for (c = 0; c < size; c++)
        array[c]=c+1;
   
    minimum = array;
    *minimum = *array;
   
    for (c = 1; c < size; c++)
    {
        if (*(array+c) > *minimum)
        {
           *minimum = *(array+c);
           location = c+1;
        }
    }
   
    printf("Maximum element found at location %d and it's value is %d.\n", location, *minimum);
    return 0;
}
