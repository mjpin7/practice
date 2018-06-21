
public class HeapTester {
	
	public static void main(String[] args)
	{
		Heap myHeap = new Heap(10);
		
		myHeap.insert(45);
		myHeap.insert(65);
		myHeap.insert(5);
		myHeap.insert(189);
		myHeap.printHeap();
		System.out.println("Removed the max from the heap: " + myHeap.removeMax());
		myHeap.printHeap();
		System.out.println("Removed the max from the heap: " + myHeap.removeMax());
		myHeap.printHeap();
		
		int[] myArray = {45, 12, 67, 123, 46};
		
		System.out.println("Unsorted array before heap-sort");
		for(int i = 0; i < myArray.length; i++)
		{
			System.out.print(myArray[i] + " ");
		}
		System.out.println();
		
		myHeap.heapSort(myArray);
		
		System.out.println("Sorted array after heap-sort");
		for(int i = 0; i < myArray.length; i++)
		{
			System.out.print(myArray[i] + " ");
		}
		System.out.println();
	}

}
