#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

/*
  This threshold signifies when we should stop merge sort and call insertion sort. Say for example we try to sort 10000 items, by the time
  we have a sub array of 10 elements, the array is short and sorted enough that insertion sort would perform better than merge sort.
*/
#define THRESHOLD 10

typedef int (*cmp_t)(const void *, const void *);

void mergeSort(void *, size_t, size_t, cmp_t);
int isSorted(void *, size_t, size_t, cmp_t);
void byteSwap(void *, void *, size_t);

#endif
