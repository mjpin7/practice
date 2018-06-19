
public class BinarySearch {
	
	public static int binarySearch(int[] arr, int target)
	{
		int high = arr.length - 1, low = 0, mid;
		
		while(low <= high)
		{
			mid = (low + high) / 2;
			
			if(arr[mid] == target)
				return mid;
			else if(target < arr[mid])
				high = mid - 1;
			else if(target > arr[mid])
				low = mid + 1;
		}
		
		return -1;
	}
	
	public static int recurBinarySearch(int[] arr, int target, int high, int low)
	{
		int mid = (low + high) / 2;
		
		if(high < low)
			return -1;
		
		if(arr[mid] == target)
			return mid;
		else if(target < arr[mid])
			return recurBinarySearch(arr, target, mid - 1, low);
		else if(target > arr[mid])
			return recurBinarySearch(arr, target, high, mid + 1);
		
		return -1;
	}

}
