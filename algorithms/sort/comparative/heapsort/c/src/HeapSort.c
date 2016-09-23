#include <stdio.h>
#include <stdlib.h>
#include "HeapSort.h"

static void buildHeap(void *, size_t, size_t, int (*cmp)(const void *, const void *));
static void siftDown(void *, int, int, size_t, int (*cmp)(const void *, const void *));
static int childSearch(void *, int, int, size_t, int (*cmp)(const void *, const void *));
static int calParentIndex(int);
static int calLeftChildIndex(int);

void heapSort(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    /*
      We first build the heap so that the largest array is at the root.
    */
    buildHeap(base, nitems, memSize, cmp);

    int end = nitems - 1; /*Remember that arrays are zero based. */

    while(end > 0)
    {
        char *endElementPtr = ((char *)base + (end * memSize)); /*offset to the last non-sorted element in the heap.*/
        byteSwap(endElementPtr, base, memSize); /*Swap that element with the root.*/
        end--; /*Shrink the size of the search space.*/
        siftDown(base, 0, end, memSize, cmp); /*The heap is now out of order and so we must fix it.*/
    }
}

static void buildHeap(void *base, size_t nitems, size_t memSize, int (*cmp)(const void *, const void *))
{
    int start = calParentIndex(nitems - 1); /*This will get us the parent node in some subtree.*/

    while(start >= 0)
    {
        siftDown(base, start, nitems - 1, memSize, cmp);
        start--; /*go to the next parent node.*/
    }
}

static void siftDown(void *base, int start, int end, size_t memSize, int (*cmp)(const void *, const void *))
{
    int childIndex = childSearch(base, start, end, memSize, cmp); /*Finds the maximum child down the heap.*/

    char *currNodePtr = ((char *)base + (start * memSize));
    char *childNodePtr = ((char *)base + (childIndex * memSize));

    while(cmp(currNodePtr, childNodePtr) > 0) /*Keep going up until you find a child that is greater than you.*/
    {
        childIndex = calParentIndex(childIndex); /*Get the next parent node of the current child.*/
        childNodePtr = ((char *)base + (childIndex * memSize));
    }

    byteSwap(currNodePtr, childNodePtr, memSize); /*We know that we have one of the smallest elements, so put it as a leaf node.*/

    while(childIndex > start)
    {
        childIndex = calParentIndex(childIndex);
        childNodePtr = ((char *)base + (childIndex * memSize));
        byteSwap(currNodePtr, childNodePtr, memSize);
    }
}

static int childSearch(void *base, int start, int end, size_t memSize, int (*cmp)(const void *, const void *))
{
    int currIndex = start;
    int leftChildIndex = calLeftChildIndex(currIndex);

    while(leftChildIndex <= end) /*Keep going down until you reach the lowest depth in the heap*/
    {
        currIndex = leftChildIndex; /*Assume that the left child has the greatest value.*/

        if(leftChildIndex + 1 <= end) /*Check if there is a right child to compare*/
        {
            char *leftChildPtr = ((char *)base + (leftChildIndex * memSize));
            char *rightChildPtr = ((char *)base + ((leftChildIndex + 1) * memSize));

            if(cmp(rightChildPtr, leftChildPtr) > 0) /*See if the right child is greater.*/
            {
                currIndex = leftChildIndex + 1;
            }
        }

        leftChildIndex = calLeftChildIndex(currIndex);
    }

    return currIndex;
}

static int calParentIndex(int index)
{
    return ((index - 1) / 2);
}

static int calLeftChildIndex(int index)
{
    return ((2 * index) + 1);
}

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
