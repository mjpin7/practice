import java.util.Random;

public class QuickSort {
	
	/**
	 * Method for quicksort. Sorts using a random pivot to avoid the worst case complexity
	 * 
	 * @param array				The array to sort
	 * @param low				The low index
	 * @param high				The high index
	 */
	static void quickSort(int[] array, int low, int high)
	{
		if(low == high)
			return;
		
		// Get low and high
		int l = low, r = high;
		
		// Get a pivot being a random value between low and high
		Random rand = new Random(System.currentTimeMillis());
		int pivot = array[(rand.nextInt((high - low) + 1) + low)];
		
		// Loop while l < r
		while(l < r)
		{
			// Move l to the right until it found a value >= pivot
			while(array[l] < pivot)
				l++;
			
			// Move r to the left until found a value <= pivot
			while(array[r] > pivot)
				r--;
			
			// If l <= r, swap values and update l and r
			if(l <= r)
			{
				int temp = array[l];
				array[l] = array[r];
				array[r] = temp;
				l++;
				r--;
			}
		}
		
		// Now will have an array with [low....l] < pivot <= [l+1...high]
		
		// If the low variable is less than the r variable, partition again
		if(low < r)
			quickSort(array, low, r);
		
		// If the high variable is greater than the l variable, partition again
		if(high > l)
			quickSort(array, l, high);
	}
	
	
	public static void main(String[] args)
	{
		int[] myArray = {45, 63, 12, 76, 1, 23};
		
		System.out.println("Unsorted array: ");
		for(int i = 0; i < myArray.length; i++)
			System.out.print(myArray[i] + " ");
		System.out.println();
		
		
		quickSort(myArray, 0, myArray.length - 1);
		
		
		System.out.println("Sorted array: ");
		for(int i = 0; i < myArray.length; i++)
			System.out.print(myArray[i] + " ");
		System.out.println();
	}

}
