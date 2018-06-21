#include <iostream>
#include "Heap.h"

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* CONSTRUCTOR */
Heap::Heap(int capac)
{
    this->capacity = capac;
    this->size = 0;
    this->arr = new int[capac];
}

/**
 * Function to heapify from an index (sift a value down)
 * 
 * @param index			The index to start from
 */
void Heap::maxHeapify(int index)
{
    // Get the right and left children
    int left = index * 2;
    int right = index * 2 + 1;

    // Set the initial largest to the index
    int largest = index;

    // Get the largest value of the two children and the index
    if(left <= this->size && this->arr[left] > this->arr[largest])
        largest = left;
    
    if(right <= this->size && this->arr[right] > this->arr[largest])
        largest = right;

    // If the largest is not the index, swap the index and the largest and recursively call to heapify
    if(largest != index)
    {
        swap(this->arr[index], this->arr[largest]);
        maxHeapify(largest);
    }
}

/**
 * Heapify Function for the Function "heapSort". Uses root at index 0 instead of 1 like usual
 * 
 * @param arr				The array to heapify
 * @param index				The index to heapify from
 * @param size				The size of the heap
 */
void Heap::maxHeapify(int *arr, int index, int size)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest;

    // If the left child is larger than the index, set the largest to the left child index
	if(left < size && arr[left] > arr[index])
		largest = left;
	// Else, the index is the largest
	else
		largest = index;
				
	// Check if the right child is larger than the largest 
	if(right < size && arr[right] > arr[largest])
		largest = right;

    if(largest != index)
    {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, size);
    }
}

/**
 * Function to insert a value into the heap
 * 
 * @param value				The value to insert
 */
void Heap::insert(int value)
{
    if(this->size == this->capacity - 1)
    {
        cout << "Could not insert, heap full" << endl;
        return;
    }

    this->size++;
    int index = this->size;

    this->arr[index] = value;
    siftUp(index);

    cout << "Inserted value " << value << " into the heap!" << endl;
}

/**
 * Function to sift a value up from an index
 * 
 * @param index				The index to sift up from
 */
void Heap::siftUp(int index)
{
    while(index != 1 && this->arr[index / 2] < this->arr[index])
    {
        swap(this->arr[index], this->arr[index / 2]);
        index = index / 2;
    }
}

/**
 * Function to remove and return the max value in the heap
 * 
 * @return			The removed max number 
 */
int Heap::removeMax()
{
    if(isEmpty())
    {
        cout << "Heap empty" << endl;
        return -1;
    }

    if(this->size == 1)
    {
        this->size--;
        return this->arr[1];
    }

    int num = this->arr[1];

    this->arr[1] = this->arr[this->size];
    this->size--;
    maxHeapify(1);

    return num;
}

/**
 * Method that takes in an unsorted array and sorts it using in-place heapsort
 * 
 * @param array				Unsorted aray to be sorted
 * @param n                 The size of the array
 */
void Heap::heapSort(int *array, int n)
{
    for(int i = n / 2 - 1; i >=0; i--)
        maxHeapify(array, i, n);

    for(int i = n - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        maxHeapify(array, 0, i);
    }
}
/**
 * Method to print the heap
 */
void Heap::printHeap()
{
    for(int i = 1; i <= this->size; i++)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Heap *myHeap = new Heap(10);

    myHeap->insert(45);
	myHeap->insert(65);
	myHeap->insert(5);
	myHeap->insert(189);
	myHeap->printHeap();
	cout << "Removed the max from the heap: " << myHeap->removeMax() << endl;
	myHeap->printHeap();
	cout << "Removed the max from the heap: " << myHeap->removeMax() << endl;
	myHeap->printHeap();
		
	int myArray[] = {45, 12, 67, 123, 46};
		
	cout << "Unsorted array before heap-sort" << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << myArray[i] << " ";
	}
	cout << endl;
		
	myHeap->heapSort(myArray, 5);
		
	cout << "Sorted array after heap-sort" << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << myArray[i] << " ";
	}
	cout << endl;

    return 0;
}