#include <stdio.h>
#include <stdlib.h>

/*
  This threshold signifies when we should stop quick sort and call insertion sort. Say for example we try to sort 10000 items, by the time
  we have a sub array of 20 elements, the array is short and sorted enough that insertion sort would perform better than quick sort.
*/
#define THRESHOLD 20

void quickSort_h(void *, size_t, size_t, int (*cmp)(const void *, const void *));
void quickSort(void *, int, int, size_t, int (*cmp)(const void *, const void *));
int qSortPartition(void *, int, int, size_t, int (*cmp)(const void *, const void *));
void insertionSort(void *, size_t, size_t, int (*cmp)(const void *, const void *));
int isSorted(void *, size_t, size_t, int (*cmp)(const void *, const void *));
int cmp(const void *, const void *);
void byteSwap(void *, void *, size_t);

int main()
{
    size_t i;
    int a[] = {200, 1, 99, 23, 56, 207, 369, 136, 147, 21, 4, 75, 36, 12};

    size_t numberOfElements = sizeof(a)/sizeof(a[0]);

    /*
     No point in performing quick sort if it does not have more than 1 elements and if
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

void quickSort_h(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    quickSort(base, 0, nitems - 1, memSize, cmp);
    /*insertionSort(base, nitems, memSize, cmp);*/
}

/*
  Here we are doing a tail recurse optimization and using our threshold value(20) to know
  when to move to Insertion Sort.
*/
void quickSort(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    while(first < last)
    {
        int pivot;

        pivot = qSortPartition(base, first, last, memSize, cmp);

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
 Here we find the median of the first, middle and last element and we will use
 that as are starting pivot.
*/
int qSortPartition(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *start = base;
    char *firstPtr = start + (first * memSize);
    char *lastPtr = start + (last * memSize);

    int mid = first + (last - first) / 2;
    char *midPtr = start + (mid * memSize);

    /* Find the larger of the two */
    int pivot = cmp(firstPtr, midPtr) > 0 ? first : mid;
    char *pivotPtr = start + (pivot * memSize);

    /* Find the smallest one. */
    if(cmp(pivotPtr, lastPtr) > 0)
    {
        pivot = last;
        pivotPtr = start + (pivot * memSize);
    }

    /* Put the pivot at the front of the list. */
    byteSwap(pivotPtr, firstPtr, memSize);
    pivot = first;
    pivotPtr = start + (pivot * memSize);

    while(last - first > THRESHOLD)
    {
        /*
           if the value we have is less than the element at the lastPtr,  move the pivot up
           by 1, else move first.
        */
        if(cmp(firstPtr, lastPtr) <= 0)
        {
            byteSwap(pivotPtr, firstPtr, memSize);
            pivot++;
            pivotPtr = start + (pivot * memSize);
        }

        first++;
        firstPtr = start + (first * memSize);
    }

    /*
       finally swap the pivot with the last element. At this point, all elements to the
       left of the pivot are less than it and vice versa.
    */
    byteSwap(pivotPtr, lastPtr, memSize);

    return pivot;
}

void insertionSort(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
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
  A > B = 1, A < B = -1, (A == B) = 0
*/
int cmp(const void *a, const void *b)
{
   const int *A = a;
   const int *B = b;
   return (*A > *B) - (*A < *B);
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
