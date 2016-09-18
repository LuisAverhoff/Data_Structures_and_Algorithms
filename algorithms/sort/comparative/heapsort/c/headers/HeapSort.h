#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

void heapSort(void *, size_t, size_t, int (*cmp)(const void *, const void *));
void buildHeap(void *, size_t, size_t, int (*cmp)(const void *, const void *));
void siftDown(void *, int, int, size_t, int (*cmp)(const void *, const void *));
int childSearch(void *, int, int, size_t, int (*cmp)(const void *, const void *));
int calParentIndex(int);
int calLeftChildIndex(int);
void byteSwap(void *, void *, size_t);

#endif
