
public class InsertionSort {
	
	/**
	 * Method to sort an array using in-place Insertion sort
	 * 
	 * @param array				The array to sort
	 */
	static void sort(int[] array)
	{
		// Get length
		int size = array.length;
		
		// Loop through array
		for(int i = 1; i < size; i++)
		{
			// Get value at index
			int value = array[i];
			int j = i - 1;
			
			// Move all necessary values over
			while(j >= 0 && array[j] > value)
			{
				array[j + 1] = array[j];
				j--;
			}
			
			// Insert value
			array[j + 1] = value;
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
