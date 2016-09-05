#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 20

void quickSort(void *, size_t, size_t, int (*cmp)(const void *, const void *));
void quickSort_r(void *, int, int, size_t, int (*cmp)(const void *, const void *));
int qSortPartition(void *, int, int, size_t, int (*cmp)(const void *, const void *));
void insertion_sort(void *, size_t, size_t, int (*cmp)(const void *, const void *));
int is_sorted(void *, size_t, size_t, int (*cmp)(const void *, const void *));
int cmp(const void *, const void *);
void Swap(void *, void *, size_t);

int main()
{
    unsigned int i;
    int a[] = {200, 1, 99, 23, 56, 207, 369, 136, 147, 21, 4, 75, 36, 12};

    size_t numberOfElements = sizeof(a)/sizeof(a[0]);

    if(numberOfElements > 1 && !is_sorted(a, numberOfElements, sizeof(int), cmp))
    {
        quickSort(a, numberOfElements, sizeof(int), cmp);
    }

    for(i = 0; i < numberOfElements; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

void quickSort(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    quickSort_r(base, 0, nitems - 1, memSize, cmp);
    insertion_sort(base, nitems, memSize, cmp);
}

void quickSort_r(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    while(last - first > THRESHOLD)
    {
        int pivot;

        pivot = qSortPartition(base, first, last, memSize, cmp);

        quickSort_r(base, first, pivot - 1, memSize, cmp);
        first = last + 1;
    }
}

int qSortPartition(void *base, int first, int last, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *carray = (char *)base;

    int pivot, mid = first + (last - first) / 2;

    pivot = cmp(&carray[first * memSize], &carray[mid * memSize]) > 0 ? first : mid;

    if(cmp(&carray[pivot * memSize], &carray[last * memSize]) > 0)
    {
        pivot = last;
    }

    Swap(&carray[pivot * memSize], &carray[first * memSize], memSize);
    pivot = first;

    while(first < last)
    {
        if(cmp(&carray[first * memSize], &carray[last * memSize]) <= 0)
        {
            Swap(&carray[pivot * memSize], &carray[first * memSize], memSize);
            pivot++;
        }

        first++;
    }

    Swap(&carray[pivot * memSize], &carray[last * memSize], memSize);

    return pivot;
}

void insertion_sort(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *carray = (char *)base;
    unsigned int i;
    int j;

    for(i = 0; i < nitems; i++)
    {
        j = i;
        while(j > 0 && cmp(&carray[j * memSize], &carray[(j - 1) * memSize]) < 0)
        {
            Swap(&carray[j * memSize], &carray[(j - 1) * memSize], memSize);
            j--;
        }
    }
}

int is_sorted(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    char *carray = (char *)base;
    unsigned int i;

    for(i = 0; i < nitems - 1; i++)
    {
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
   return (*A > *B) - (*A < *B);
}

void Swap(void *a, void *b, size_t memSize)
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
