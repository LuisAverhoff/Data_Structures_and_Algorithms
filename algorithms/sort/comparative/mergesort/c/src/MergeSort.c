#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MergeSort.h"

static void mergeSort_recurse(void *, void *, int, int, size_t, cmp_t);
static void merge_top(void *, void *, int, int, int, size_t, cmp_t);
static void insertionSort(void *, size_t, size_t, cmp_t);

void mergeSort(void *base, size_t nitems, size_t memSize, cmp_t cmp)
{
    /*
        Merge sort requires a temporary array to write the values it has back to the original array.
        Rather than mallocing a temporary array each time we decide to merge, we only need to malloc this temp
        array once. This will speed up our execution time by a good amount but our space complexity will still be
        big-oh(N).
    */
    char *tempArr = (char *)malloc(sizeof(char) * memSize * nitems);

    if(tempArr != NULL)
    {
        mergeSort_recurse(base, tempArr, 0, nitems - 1, memSize, cmp);
        free(tempArr);
        insertionSort(base, nitems, memSize, cmp);
    }
}

static void mergeSort_recurse(void *base, void *tempArr, int start, int last, size_t memSize, cmp_t cmp)
{
    if(last - start < THRESHOLD) return;

    int splitIndex = start + ((last - start) / 2); /*Makes it less likely for an overflow to occur.*/

    /*
        Break the array into two sub arrays; one which the represents the left most side of the array up
        until the splitIndex variable and one which the represents the right most side of the array up until the end
        variable. Then, once we recurse far enough that we only have one array to sort, we start merging each
        sub array until our array is sorted.
    */
    mergeSort_recurse(base, tempArr, start, splitIndex, memSize, cmp);
    mergeSort_recurse(base, tempArr, splitIndex + 1, last, memSize, cmp);
    merge_top(base, tempArr, start, splitIndex, last, memSize, cmp);
}

static void merge_top(void *base, void *tempArr, int start, int splitIndex, int last, size_t memSize, cmp_t cmp)
{
    char *leftElement;
    char *rightElement;
    char *tempElement;

    int leftIndex = start; /*Starting index for the left sub array.*/
    int rightIndex = splitIndex + 1;/*Starting index for the right sub array. */
    int tempArrIndex = start; /*Starting index for the temp array. */

    /*while we haven't reached the end of either the left or right sub array. */
    while(leftIndex <= splitIndex && rightIndex <= last)
    {
        leftElement = ((char *)base + (leftIndex * memSize)); /*offsetting to the element at left and right Index.*/
        rightElement = ((char *)base + (rightIndex * memSize));

        if(cmp(leftElement, rightElement) <= 0)
        {
            tempElement = ((char *)tempArr + (tempArrIndex * memSize));
            memcpy(tempElement, leftElement, memSize);
            leftIndex++;
            tempArrIndex++;
        }
        else
        {
            tempElement = ((char *)tempArr + (tempArrIndex * memSize));
            memcpy(tempElement, rightElement, memSize);
            rightIndex++;
            tempArrIndex++;
        }
    }

    /*
        Once the first while loop up above finishes, only one of these loops will execute and copy the elements that were left
        over from either the left or right sub array.
    */
    while(leftIndex <= splitIndex)
    {
        leftElement = ((char *)base + (leftIndex * memSize));
        tempElement = ((char *)tempArr + (tempArrIndex * memSize));
        memcpy(tempElement, leftElement, memSize);
        leftIndex++;
        tempArrIndex++;
    }

    while(rightIndex <= last)
    {
        rightElement = ((char *)base + (rightIndex * memSize));
        tempElement = ((char *)tempArr + (tempArrIndex * memSize));
        memcpy(tempElement, rightElement, memSize);
        rightIndex++;
        tempArrIndex++;
    }


    for(leftIndex = start; leftIndex <= last; leftIndex++)
    {
        leftElement = ((char *)base + (leftIndex * memSize));
        tempElement = ((char *)tempArr + (leftIndex * memSize));
        memcpy(leftElement, tempElement, memSize);
    }
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

int isSorted(void *base, size_t nitems, size_t memSize, cmp_t cmp)
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
