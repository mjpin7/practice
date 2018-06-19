
public class TesterSearch {
	
	public static void main(String[] args)
	{
		int[] myArray = {12, 34, 56, 78, 124, 345, 678, 1000};
		
		int index = BinarySearch.binarySearch(myArray, 78);
		
		if(index > 0)
			System.out.println("Found number 78 at index " + index + " iteratively");
		else
			System.out.println("Could not find 78 iteratively");
		
		index = BinarySearch.recurBinarySearch(myArray, 678, myArray.length - 1, 0);
		
		if(index > 0)
			System.out.println("Found number 678 at index " + index + " recursively");
		else
			System.out.println("Could not find 678 recursively");
	}

}
