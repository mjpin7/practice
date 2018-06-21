/**
 * Class for a heap. Methods implemented are using a max-heap
 * 
 * @author MPinheiro
 *
 */
public class Heap {
	
	private int[] arr;
	private int capacity;
	private int size;
	
	/* CONSTRUCTOR */
	public Heap(int capac)
	{
		this.capacity = capac;
		this.size = 0;
		this.arr = new int[capac];
	}
	
	/**
	 * Method to heapify from an index (sift a value down)
	 * 
	 * @param index			The index to start from
	 */
	public void maxHeapify(int index)
	{
		// Get the right and left children of the node
		int left = 2 * index;
		int right = 2 * index + 1;
		int largest;
		
		// If the left child is larger than the index, set the largest to the left child index
		if(left <= this.size && this.arr[left] > this.arr[index])
			largest = left;
		// Else, the index is the largest
		else
			largest = index;
		
		// Check if the right child is larger than the largest 
		if(right <= this.size && this.arr[right] > this.arr[largest])
			largest = right;
		
		// If the largest value is NOT the index, swap the two values and recursively call the method to keep sifting down
		if(largest != index)
		{
			int temp = this.arr[index];
			this.arr[index] = this.arr[largest];
			this.arr[largest] = temp;
			maxHeapify(largest);
		}
	}
	
	/**
	 * Heapify method for the method "heapSort". Uses root at index 0 instead of 1 like usual
	 * 
	 * @param arr				The array to heapify
	 * @param index				The index to heapify from
	 * @param size				The size of the heap
	 */
	private void maxHeapify(int[] arr, int index, int size)
	{
		// Get the right and left children of the node
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
				
		// If the largest value is NOT the index, swap the two values and recursively call the method to keep sifting down
		if(largest != index)
		{
			int temp = arr[index];
			arr[index] = arr[largest];
			arr[largest] = temp;
			maxHeapify(arr, largest, size);
		}
	}
	
	/**
	 * Method to insert a value into the heap
	 * 
	 * @param value				The value to insert
	 */
	public void insert(int value)
	{
		// If the heap is full
		if(this.size == capacity - 1)
		{
			System.out.println("Could not insert, heap full");
			return;
		}
		
		// Update the size, insert the value at the end and sift up
		this.size++;
		int index = this.size;
		this.arr[index] = value;		
		siftUp(index);		
		
		System.out.println("Inserted value " + value + " into the heap!");
	}
	
	/**
	 * Method to sift a value up from an index
	 * 
	 * @param index				The index to sift up from
	 */
	public void siftUp(int index)
	{
		// Keep sifting up until no longer needed
		while(index != 1 && this.arr[index / 2] < this.arr[index])
		{
			// Swap the elements and update the index so it points to the parent
			int temp = this.arr[index];
			this.arr[index] = this.arr[index / 2];
			this.arr[index / 2] = temp;
			index = index / 2;
		}
	}
	
	/**
	 * Method to remove and return the max value in the heap
	 * 
	 * @return			The removed max number 
	 */
	public int removeMax()
	{
		// If the heap is empty
		if(isEmpty())
		{
			System.out.println("Heap Empty");
			return -1;
		}
		
		// If the heap is of size 1
		if(this.size == 1)
		{
			this.size--;
			return this.arr[1];
		}
		
		
		// Save the number to return
		int num = arr[1];
		// Set the root equal to the last leaf node
		arr[1] = arr[this.size];
		// Decrease size
		this.size--;
		// Heapify's the heap. Sifts the value down
		maxHeapify(1);
		
		return num;
	}
	
	/**
	 * Method that takes in an unsorted array and sorts it using in-place heapsort
	 * 
	 * @param array				Unsorted aray to be sorted
	 */
	public void heapSort(int[] array)
	{
		// Build heap
		for(int i = array.length / 2 - 1; i >= 0; i--)
			maxHeapify(array, i, array.length);
		
		// Go through the heap, removing max and heapifying it again
		for(int i = array.length - 1; i >= 0; i--)
		{
			int temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			
			maxHeapify(array, 0, i);
		}
			
	}
	
	/**
	 * Method to return but not remove the max value
	 * 
	 * @return
	 */
	public int getMax()
	{
		return this.arr[1];
	}
	
	/**
	 * Method to print the heap
	 */
	public void printHeap()
	{
		for(int i = 1; i <= this.size; i++)
		{
			System.out.print(this.arr[i] + " ");
		}
		System.out.println();
	}
	
	/**
	 * Method to get the size of the heap
	 * 
	 * @return				The size
	 */
	public int getSize()
	{
		return this.size;
	}
	
	/**
	 * Method to see if the heap is empty
	 * 
	 * @return				True if the heap is empty
	 */
	public boolean isEmpty()
	{
		return (this.size == 0);
	}

}
