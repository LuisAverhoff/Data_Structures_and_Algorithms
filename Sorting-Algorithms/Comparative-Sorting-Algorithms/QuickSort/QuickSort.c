#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
  This threshold signifies when we should stop quicksort and call insertion sort. Say for example we try to sort 10000 items, by the time
  we have a subarray of 20 elements, the array is short and sorted enough that insertion sort would perform better than quick sort.
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
    /*
      Throughout this source code, if you see an unsigned int, more than likely I'm using an unsigned int because I'm comparing to
      a variable of type size_t which is also an unsigned int or long.
    */
    unsigned int i;
    int a[] = {200, 1, 99, 23, 56, 207, 369, 136, 147, 21, 4, 75, 36, 12};

    size_t numberOfElements = sizeof(a)/sizeof(a[0]);

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
    insertionSort(base, nitems, memSize, cmp);
}

void quickSort(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    while(last - first > THRESHOLD) // Once we have a subarray that has less than 20 elements
    {
        int pivot;

        pivot = qSortPartition(base, first, last, memSize, cmp);
        
        /*
          Here we are checking which is easier to recurse by looking at if the subarray on the left is shorter than the
          one on the right and vice versa.
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

int qSortPartition(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *carray = (char *)base;

    int pivot, mid = first + (last - first) / 2;
    
    // Find the larger of the two
    pivot = cmp(&carray[first * memSize], &carray[mid * memSize]) > 0 ? first : mid; 
    
    // Find the smallest one.
    if(cmp(&carray[pivot * memSize], &carray[last * memSize]) > 0)
    {
        pivot = last;
    }
    
    // Put the pivot at the front of the list.
    byteSwap(&carray[pivot * memSize], &carray[first * memSize], memSize);
    pivot = first;

    while(first < last)
    {
        // if the value we have is less than the element at the end, move the pivot up by 1, else move first.
        if(cmp(&carray[first * memSize], &carray[last * memSize]) <= 0)
        {
            byteSwap(&carray[pivot * memSize], &carray[first * memSize], memSize);
            pivot++;
        }

        first++;
    }
    
    // finally swap the pivot with the last element. At this point, all elements to the left of the pivot are less than it and vice versa.
    byteSwap(&carray[pivot * memSize], &carray[last * memSize], memSize);

    return pivot;
}

void insertionSort(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *carray = (char *)base;
    unsigned int i;
    int j;

    for(i = 0; i < nitems; i++)
    {
        j = i;
        while(j > 0 && cmp(&carray[j * memSize], &carray[(j - 1) * memSize]) < 0)
        {
            byteSwap(&carray[j * memSize], &carray[(j - 1) * memSize], memSize);
            j--;
        }
    }
}

int isSorted(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *carray = (char *)base;
    unsigned int i;

    for(i = 0; i < nitems - 1; i++)
    {
        // Simply check if the current element is greater than the next element.
        if(cmp(&carray[i * memSize], &carray[(i + 1) * memSize]) > 0)
        {
            return 0;
        }
    }

    return 1;
}

int cmp(const void *a, const void *b)
{
   const int *A = a, *B = b;
   // A > B = 1, A < B = -1, A == B = 0
   return (*A > *B) - (*A < *B);
}

// The main way that this function is swapping is by swapping out the bytes in each iteration.
void byteSwap(void *a, void *b, size_t memSize)
{
    char tmp;
    char *aa = a, *bb = b;

    do
    {
        tmp = *aa;
        *aa++ = *bb;
        *bb++ = tmp;
    }
    while(--memSize > 0);
}
