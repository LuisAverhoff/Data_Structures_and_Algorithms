# Data Structures and Algorithms
This repository will house a collection of common data structures and algorithms used to solve many different programming problems. This will range from:

- List(ArrayList, LinkedList etc)
- Stacks and Queues
- Sorting Algorithms(Merge Sort, Quick sort, Radix Sort etc)
- Trees(BST, AVL, MST etc)
- Graph Searching Algorithms(Depth First Search, Breadth First Search)
- and more


### Stack

A Stack is a Data Structure that has the property of Last-In-First-Out(LIFO) with two principal methods, push and pop. 
Push inserts an element at the top of the stack while pop remove the last element inserted on the stack; Both of these operation are 
done in big-oh(**1**). An additional method called peek serves as way to view the element at the top of the stack without removing it.

To cement the concept of a stack, think of stacking books on top of one another. The way that you would remove a stack of books from one another is to constantly remove the top most book until there is no more books left to remove. This is the fundamental idea behind a stack.


### Queue

Queue is an abstract data structure(ADT) that has operations and properties similar to a stack. Queue has the properties of FIFO which means that the data stored first, is the one that will be accessed first. The main functions that a Queue has is enqueue(push equivalent) which pushes the element to end of the queue and dequeue(pop equivalent) whihc removes the first element on the Queue;
Both of these operations take big-oh(**1**). 

To cement the concept of a queue, think of a clinic line. The first person in the line has the highest priortity and is the first person to be treated.


### Quicksort

Quicksort is one of the many efficient comparative sorting algorithms next to Mergesort and Heapsort. In many implementations, Quicksort has the property of not being stable(meaning that relative ordering of each item is not preserve) and in-place(no additional memory overhead unlike mergesort). Note, it is possible to make Quicksort a stable comparative algorithm.

In the average case, the algorithm takes big-oh(**NlogN**) comparsions to sort n items. A very short intuitive reason for why it takes nlogn on average is because in the average case, you partition the array in half(log n) and you do this n times. However, the worst case is big-oh(**N^2**) if you make the left most element the pivot and the array is sorted. The same would happen if you were to make the right most element the pivot and the array was sorted in the reverse order. There are various optimizations one could take in order to reduce the possibility of this happening such as picking a random pivot or by finding the median of the first, middle and last element.

Procedure:

- choose a pivot either randomly, by finding the median of the first, middle and last element, or simply choose either the leftmost , middle or rightmost element as the pivot.
- Partition the list so that all elements less than the pivot are to the left of it and all elements that are greater than the pivot are to the right of it.
- Recursively apply the first two steps until your subarray has only one element left.


### Heapsort

Heapsort is a comparative sorting algorithm to sort a collection of data by creating a special type of binary tree called the heap. The two main heaps of use to consider in heapsort is a min heap and a max heap. In a max heap, the largest value in the heap is at the root while in a min heap, the smallest value in the heap is at the root. One of the nice things about the heap is how easy it is to represent a min or max heap in an array and access its members. 

Assuming that the beginning of the heap is at index 0 and not index 1, then the forumlas to calculate the index of the parent, the left child and the right child are as follows:

- **(N - 1) / 2**
- **2 * i + 1**
- **2 * i + 2**

If the beginning of the heap is at index 1

- **N / 2**
- **2 * i**
- **2 * i + 1**

Procedure:

- The first step in this algorithm is to build the heap(it could be either a min or max heap) in such a way that either all the elements below the root are less than the root or greater than the root. This also applies to all subtrees in the heap as well.
- Remove the top most item and replace it with the right most leaf. This element is now in its final position and does not have to moved ever again.
- Shrink the size of your search space by 1 because now you have one less element in the heap to look at.
- The heap is out of order now and you must fix it(refer to step 1).
- Repeat all these steps until all your elements are in there final position.

The worst running time for Heapsort is big oh(**NlogN**). Building the heap takes big-oh(**N**) because you might have to go all the way down to end. Think of it like this, All the nodes at the bottom of the tree dont have to be moved at all because they are already at the bottom. All the nodes at height at 1, have to be moved down 1 level. All the nodes at height 2, have to moved down 2 levels and so on. So you can see that the amount of work done is different on each height of the tree and is not exactly big-oh(**logN**). Fixing the heap so that it maintains the heap property takes big-oh(**NlogN**). If you have **K** elements, it would take log(**K**) time. Doing this N times gives us big-oh(**NlogN**). Putting this all together and we get that heapsort is T(N) = big-oh(**N + NlogN**) = big-oh(**NlogN**).  

### Binary Search

Binary Search is an algorithm that finds the position of a value within a **sorted array**. It is one of the fastest search algorithm with the constraint that the array is sorted.

Procedure:

- Calculate the midpoint i.e **low + ((high - low) / 2)**. This instead of **(high + low) / 2** lessen the possibility of getting an overflow.
- If the element that you're are looking is less than the element in the middle, then you know that the element has to be to the left of the array given the fact that the array is sorted. The same logic applies if the element was greater than the element in the middle.
- Apply step 1 and 2 until you find the element that you are looking for or your search space becomes zero.

Binary search in the worst case performs in big-oh(**LogN**) and uses big-oh(**1**) space. The reason for this is because in each iteration, we are essentially splitting up our search in half(**N/2**)
