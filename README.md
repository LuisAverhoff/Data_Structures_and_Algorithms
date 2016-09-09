# Data Structures and Algorithms
This repository will house a collection of common data structures and algorithms used to solve many different programming problems. This can range from:

- List(ArrayList, LinkedList etc)
- Stacks and Queues Implementation with lists
- Sorting(Merge Sort, Quick sort, Radix Sort etc)
- Trees(BST, AVL, MST etc)
- Graph Searching Algorithms(Depth First Search, Breadth First Search)
- and more


### Stack

A Stack is a Data Structure that has the property of Last-In-First-Out(LIFO) with two principal methods, push and pop. 
Push inserts an element at the top of the stack while pop remove the last element inserted on the stack; Both of these operation are 
done in constant time. An additional method called peek serves as way to view the element at the top of the stack without removing it.

To cement the concept of a stack, think of stacking books on top of one another. The way that you would remove a stack of books from one 
another is to constantly remove the top most book until there is no more books to remove. This is the fundamental idea behind a stack.


### Quicksort

Quicksort is one of the many efficient comparative sorting algorithms next to Mergesort and Heapsort. In many implementations, Quicksort has the property of not being stable(meaning that relative ordering of each item is not preserve) and in-place(no additional memory overhead unlike mergesort). Note, it is possible to make Quicksort a stable comparative algorithm.

In the average case, the algorithm takes nlogn comparsions to sort n items. A very short intuitive reason for why it takes nlogn on average is because in the average case, you partition the array in half(log n) and you do this n times. However, the worst case is n^2 but you can make various optimizations to make this almost to occur such as picking a random pivot or by finding the median by comparing the first, middle and last element.

Procedure:

- choose a pivot either randomly, by finding the median of the first, middle and last element, or simply choose either the leftmost , middle or rightmost element as the pivot.
- Partition the list so that all elements less than the pivot are to the left of it and all elements that are greater than the pivot are to the right of it.
- Recursively apply the first two steps until your subarray has only one element left.
