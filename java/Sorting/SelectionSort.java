
public class SelectionSort {
	
	/**
	 * Method to sort an array using in-place selection sort
	 * 
	 * @param array				The array to sort
	 */
	static void sort(int[] array)
	{
		// Get the size
		int size = array.length;
		
		// Loop through the array
		for(int i = 0; i < size - 1; i++)
		{
			// Set the min to i
			int min = i;
			
			// Find the minimum value in the sub array
			for(int j = i + 1; j < size; j++)
			{
				if(array[j] < array[min])
					min = j;
			}
			
			// Swap the value at the beginning with the min value
			int temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}

	public static void main(String[] args) 
	{
		int[] myArray = {45, 63, 12, 76, 1, 23};
		
		System.out.println("Unsorted array: ");
		for(int i = 0; i < myArray.length; i++)
			System.out.print(myArray[i] + " ");
		System.out.println();
		
		
		sort(myArray);
		
		
		System.out.println("Sorted array: ");
		for(int i = 0; i < myArray.length; i++)
			System.out.print(myArray[i] + " ");
		System.out.println();

	}

}
