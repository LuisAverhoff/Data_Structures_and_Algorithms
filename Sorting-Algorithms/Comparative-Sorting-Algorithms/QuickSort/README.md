#Quicksort Algorithm

Quicksort is one of the many efficient comparative sorting algorithms next to Mergesort and Heapsort. In many implementations, 
Quicksort has the property of not being stable(meaning that relative ordering of each item is not preserve) and 
in-place(no additional memory overhead unlike mergesort). Note, it is possible to make Quicksort a stable comparative algorithm.

In the average case, the algorithm takes nlogn comparsions to sort n items. A very short intuitive reason for why it takes nlogn on average is because
in the average case, you partition the array in half(log n) and you do this n times. However, the worst case is n^2 but you can make various 
optimizations to make this almost to occur such as picking a random pivot or by finding the median by comparing the first, middle and last element.

### Procedure:
- choose a pivot either randomly, by finding the median of the first, middle and last element, or simply choose either the leftmost
, middle or rightmost element as the pivot.
- Partition the list so that all elements less than the pivot are to the left of it and all elements that are greater than the pivot are to the
right of it.
- Recursively apply the first two steps until your subarray has only one element left.
