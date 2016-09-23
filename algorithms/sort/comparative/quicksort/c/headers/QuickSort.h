#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

/*
  This threshold signifies when we should stop quick sort and call insertion sort. Say for example we try to sort 10000 items, by the time
  we have a sub array of 10 elements, the array is short and sorted enough that insertion sort would perform better than quick sort.
*/
#define THRESHOLD 10

typedef int (*cmp_t)(const void *, const void *);

void quickSort_h(void *, size_t, size_t, cmp_t);
int isSorted(void *, size_t, size_t, cmpt_t);
void byteSwap(void *, void *, size_t);

#endif
