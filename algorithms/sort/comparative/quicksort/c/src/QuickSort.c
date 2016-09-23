#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

void quickSort_h(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    quickSort(base, 0, nitems - 1, memSize, cmp);
    insertionSort(base, nitems, memSize, cmp);
}

/*
  Here we are doing a tail recurse optimization and using our threshold value(20) to know
  when to move to Insertion Sort.
*/
static void quickSort(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    while(last - first < THRESHOLD)
    {
        int medianPivot = medianOfThree(base, first, last, memSize, cmp);
        int pivot = qSortPartition(base, first, last, medianPivot, memSize, cmp);

        /*
          Here we are checking which is easier to recurse by checking if the sub array
          on the left is shorter than the one on the right and vice versa.
        */
        if(pivot - first < last - pivot)
        {
            quickSort(base, first, pivot - 1, memSize, cmp);
            first = pivot + 1;
        }
        else
        {
            quickSort(base, pivot + 1, last, memSize, cmp);
            last = pivot - 1;
        }
    }
}

/*
    We compare the first, middle and last element and swap elements accordingly
*/
static int medianOfThree(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    int mid = first + ((last - first) / 2); /*Makes it less lightly for overflow to occur.*/

    char *firstPtr = (char *)base + (first * memSize);
    char *midPtr = (char *)base + (mid * memSize);
    char *lastPtr = (char *)base + (last * memSize);

    if(cmp(firstPtr, midPtr) > 0)
        byteSwap(firstPtr, midPtr, memSize);
    if(cmp(firstPtr, lastPtr) > 0)
        byteSwap(firstPtr, lastPtr, memSize);
    if(cmp(midPtr, lastPtr) > 0)
        byteSwap(midPtr, lastPtr, memSize);


    byteSwap(midPtr, ((char *)base + ((last - 1) * memSize)), memSize);
    return last - 1;
}

static int qSortPartition(void *base, int first, int last, int medianPivot, size_t memSize, int (*cmp)(const void *, const void *))
{
    int i;
    char *currentPtr;
    char *pivotIndexPtr;

    char *start = base;
    char *pivotPtr = start + (medianPivot * memSize);
    int pivotIndex = first;

    for(i = first; i < last; i++)
    {
        currentPtr = start + (i * memSize);

        if(cmp(currentPtr, pivotPtr) <= 0)
        {
            pivotIndexPtr = start + (pivotIndex * memSize);
            byteSwap(currentPtr, pivotIndexPtr, memSize);
            pivotIndex++;
        }
    }

    pivotIndexPtr = start + (pivotIndex * memSize);
    byteSwap(pivotIndexPtr, pivotPtr, memSize);
    return pivotIndex;
}

static void insertionSort(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *start = base;
    char *lastPtr = start + (nitems * memSize);
    char *top;

    for(top = start + memSize; top < lastPtr; top += memSize)
    {
        char *previous = top;
        char *current = previous - memSize;

        while(current >= start && cmp(previous, current) < 0)
        {
            byteSwap(previous, current, memSize);
            previous = current;
            current -= memSize;
        }
    }
}

int isSorted(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *start = base;
    char *lastPtr = (start + (nitems * memSize)) - memSize;

    for(; start < lastPtr; start += memSize)
    {
        /* Simply check if the current element is greater than the next element. */
        if(cmp(start, start + memSize) > 0)
        {
            return 0;
        }
    }

    return 1;
}

/*
  The main way that this function is swapping is by swapping out the bytes in each
  iteration.
*/
void byteSwap(void *a, void *b, size_t memSize)
{
    char *aa = a;
    char *bb = b;

    do
    {
        char tmp = *aa;
        *aa++ = *bb;
        *bb++ = tmp;
    }
    while(--memSize > 0);
}
