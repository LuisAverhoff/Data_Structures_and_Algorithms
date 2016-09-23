#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

typedef int (*cmp_t)(const void *, const void *);

void heapSort(void *, size_t, size_t, cmp_t);
void byteSwap(void *, void *, size_t);

#endif
