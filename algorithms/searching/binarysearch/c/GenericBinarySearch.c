#include <stdio.h>
#include <stdlib.h>

int gBinarySearch(void *, size_t, int, void *, int (*cmp)(const void *, const void *));
int cmp(const void *, const void *);

int main()
{
    int test[]= {1,3,5,7,9,11,13};
    int target = 13;

    size_t arrayLen = sizeof(test) / sizeof(test[0]);

    int index = gBinarySearch(test, sizeof(int), arrayLen, &target, cmp);

    if(index != -1)
    {
        printf("%d was found at index %d", target, index + 1);
    }
    else
        printf("The value %d does not exist in this array", target);

    return 0;
}

/*
  This is a generic version of the binary search algorithm that is made to work with any type.
*/
int gBinarySearch(void *array, size_t elemSize, int arrayLen, void *target, int (*cmp)(const void *, const void *))
{
    void *currElem;
    int low = 0, mid, high = arrayLen - 1;

    while(low <= high)
    {
        mid = low + ((high - low) / 2);
        currElem = (char *)array + (mid * elemSize);

        if(cmp(target, currElem) == 0)
            return mid;
        else if(cmp(target, currElem) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
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
