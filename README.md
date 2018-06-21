# Practice
Practice implementing various data structures and algorithms in different languages.

Flashcards for data structures: https://quizlet.com/mjpin7

## Contents
* [Dynamic Array (C++)](#dyn-array)
* [Linked List](#link-list)
* [Queue](#queue)
* [Hash Table](#hash)
* [Binary Search](#bin-search)
* [Binary Search Tree](#BST)
* [Heap/HeapSort](#heap)

---

## <a name="dyn-array"></a>Dynamic Array (C++)
  - Program to dynamically create a resizable array
  - growArray(arr, size): Doubles the size of the array. Allocates and frees memory when needed
  - printArray(arr, size): Prints the array to the console
  - getInput(arr, size): Gets input to enter into the array

## <a name="link-list"></a>Linked List
  - Implemented in C++, Python and Java(Generically)
  - size(): Finds the size of the list
  - empty(): Returns if the list is empty or not
  - value_at(index): Finds the value at a specified index
  - push_front(value): Inserts value at the beginning of the list
  - pop_front(): Removes and returns the value at the front of the list
  - push_back(): Inserts the value at the end of the list
  - pop_back(): Removes and returns the last value in the list
  - front(): Returns the first value without removing it
  - back(): Returns the last value without removing it
  - insert(index, value): Inserts value at the specified index
  - erase(index): Deletes the node at the specified index

## <a name="queue"></a>Queue (implemented using a list)
  - Implemented in C++(Template), Python and Java(Generically)
  - enqueue(value): Adds a new element to the end of the queue
  - dequeue(): Removes and a returns an element at the front of the queue
  - empty(): Checks if the queue is empty
  - printQueue(): Prints the queue to the console

## <a name="hash"></a>Hash Table (implemented using seperate chaining and linear probing)
  - Implemented in C++(Template, chaining), Python(chaining), Java(linearly probing)
  - sizeTable(): Returns the size of the table
  - isEmpty(): Checks whether the table is empty
  - insert(key, value): Inserts a key/value pair into the hash table
  - remove(key): Removes a pair in the hash map given a certain key
  - get(key): Get a value given a certain key
  - printTable(): Prints the hash table

## <a name="bin-search"></a>Binary Search
  - Implemented in C++, Python and Java
  - Implemented both iterative and recursive versions
  - On sorted array of integers

## <a name="BST"></a>Binary Search Tree
  - Implemented in C++, Python and Java
  - insert(value): To insert a value into the BST
  - inOrder(): To print the tree in "In-Order" traversal
  - delete(value): Deletes a value in the tree
  - isInTree(value): Checks whether a given value is in the tree
  - getMin(): Gets the minimum value in the BST
  - getMax(): Gets the maximum value in the BST
  - getHeight(): Gets the height of the BST

## <a name="heap"></a>Heap/HeapSort
  - Implemented in Java with root node at index 1
  - maxHeapify(index): To heapify (sift down) an index in the heap
  - insert(value): To insert a value into the heap
  - siftUp(index): To sift a value up at index, used when inserting
  - removeMax(): Remove and return the max value in the heap as well as make sure to keep heap conditions
  - heapSort(array): Takes an unsorted array and sorts it using HeapSort
  - getMax(): Returns but does not remove the max value in heap
  - printHeap(): Prints the heap
  - getSize(): Gets the size of the heap
  - isEmpty(): Checks if the heap is empty
  
