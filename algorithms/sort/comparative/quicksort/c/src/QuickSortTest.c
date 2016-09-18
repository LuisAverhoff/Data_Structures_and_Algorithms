#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

int cmp(const void *, const void *);

int main()
{
    size_t i;
    int a[] = {200, 1, 99, 23, 56, 207, 369, 136, 147, 21, 4, 75, 36, 12};

    size_t numberOfElements = sizeof(a)/sizeof(a[0]);

    /*
     No point in performing quick sort if it does not have more than 1 element and if
     the array is sorted.
    */
    if(numberOfElements > 1 && !isSorted(a, numberOfElements, sizeof(int), cmp))
    {
        quickSort_h(a, numberOfElements, sizeof(int), cmp);
    }

    for(i = 0; i < numberOfElements; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

/*
  A > B = 1, A < B = -1, (A == B) = 0
*/
int cmp(const void *a, const void *b)
{
   const int *A = a;
   const int *B = b;
   return (*A > *B) - (*A < *B);
}
