public class MergeSort {

    /**
     * Method to merge two subarrays within an array
     * 
     * @Param array             The array to merge
     * @Param l                 The left index
     * @Param m                 The middle index
     * @Param r                 The right index
     */
    public static void merge(int[] array, int l, int m, int r)
    {
        // Initialize variables and get sizes of temp arrays
        int i, j, k = l;
        int size1 = (m - l) + 1;
        int size2 = (r - m);

        // Create temp arrays
        int[] arr1 = new int[size1];
        int[] arr2 = new int[size2];

        // Copy lower half into arr1
        for(i = 0; i < size1; i++, k++)
            arr1[i] = array[k];

        // Copy upper half into arr2
        for(j = 0; j < size2; j++, k++)
            arr2[j] = array[k];

        // Reset vars
        i = 0;
        j = 0;
        k = l;

        // Loop until one of the arrays have been gone through
        while(i < size1 && j < size2)
        {
            // Copy the smallest value into the array
            if(arr1[i] < arr2[j])
            {
                array[k] = arr1[i];
                i++;
            }
            else
            {
                array[k] = arr2[j];
                j++;
            }
            k++;
        }

        // Copy the rest of the array that hasn't been gone through
        while(i < size1)
        {
            array[k] = arr1[i];
            i++;
            k++;
        }

        while(j < size2)
        {
            array[k] = arr2[j];
            j++;
            k++;
        }


    }

    /**
     * Method to divide and merge the array (Sort using merge sort)
     * 
     * @Param array             The array to sort
     * @Param left              The left index of the array
     * @Param right             The right index of the array
     */
    public static void sort(int[] array, int left, int right)
    {
        if(left < right)
        {
            int middle = (left + right) / 2;

            sort(array, left, middle);
            sort(array, middle + 1, right);

            merge(array, left, middle, right);
        }
    }

    public static void main(String[] args)
    {
        int[] myArray = {45, 63, 12, 76, 1, 23};
		
		System.out.println("Unsorted array: ");
		for(int i = 0; i < myArray.length; i++)
			System.out.print(myArray[i] + " ");
		System.out.println();
		
		
		sort(myArray, 0, 5);
		
		
		System.out.println("Sorted array: ");
		for(int i = 0; i < myArray.length; i++)
			System.out.print(myArray[i] + " ");
		System.out.println();
    }
}