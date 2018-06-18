# Practice
Practice implementing various data structures and algorithms in different languages.

Flashcards for data structures: https://quizlet.com/mjpin7

### Contents
* [Dynamic Array (C++)](#dyn-array)
* [Linked List](#link-list)
* [Queue](#queue)
* [Hash Table](#hash)

---

#### <a name="dyn-array"></a>Dynamic Array (C++)
  - Program to dynamically create a resizable array
  - growArray(arr, size): Doubles the size of the array. Allocates and frees memory when needed
  - printArray(arr, size): Prints the array to the console
  - getInput(arr, size): Gets input to enter into the array

#### <a name="link-list"></a>Linked List
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

  #### <a name="queue"></a>Queue (implemented using a list)
  - Implemented in C++(Template), Python and Java(Generically)
  - enqueue(value): Adds a new element to the end of the queue
  - dequeue(): Removes and a returns an element at the front of the queue
  - empty(): Checks if the queue is empty
  - printQueue(): Prints the queue to the console

  #### <a name="hash"></a>Hash Table (implemented using linear probing and seperate chaining)
  - Implemented in C++(Template)
  - sizeTable(): Returns the size of the table
  - isEmpty(): Checks whether the table is empty
  - insert(key, value): Inserts a key/value pair into the hash table
  - remove(key): Removes a pair in the hash map given a certain key
  - get(key): Get a value given a certain key
  - printTable(): Prints the hash table
