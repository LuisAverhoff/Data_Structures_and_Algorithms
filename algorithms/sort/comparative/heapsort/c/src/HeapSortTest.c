#include <stdio.h>
#include <stdlib.h>
#include "HeapSort.h"

int cmp(const void *, const void *);

int main()
{
    size_t i;
    int arr[] = {19, 56, 25, 17, 100, 58, 72, 1000, 98, 36, 14, 78, 125};

    size_t nitems = sizeof(arr) / sizeof(arr[0]);

    if(nitems > 1)
    {
        heapSort(arr, nitems, sizeof(int), cmp);
    }

    printf("Sorted Array: ");

    for( i =0; i < nitems; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

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
