#include <iostream>

using namespace std;

/**
 * Function to merge two subarrays within an array
 * 
 * @Param array             The array to merge
 * @Param l                 The left index
 * @Param m                 The middle index
 * @Param r                 The right index
 */
void merge(int *array, int l, int m, int r)
{
    // Initialize variables
    int i, j, k = l;

    // Get the sizes of the two temp arrays
    int size1 = (m - l) + 1;
    int size2 = (r - m);

    // Create the two temp arrays of sizes
    int arr1[size1], arr2[size2];

    // Copy lower half of array into arr1
    for(i = 0; i < size1; i++, k++)
        arr1[i] = array[k];
    
    // Copy upper half of array into arr2
    for(j = 0; j < size2; j++, k++)
        arr2[j] = array[k];

    // Reset varibles
    k = l;
    i = 0;
    j = 0;

    // Go through the arrays until one is fully gone through
    while(i < size1 && j < size2)
    {
        // Insert the smallest element into the permanant array
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

    // Empty the rest of the remaining array into the permanant array
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
 * Function to divide and merge the array (Sort using merge sort)
 * 
 * @Param array             The array to sort
 * @Param left              The left index of the array
 * @Param right             The right index of the array
 */
void sort(int *array, int left, int right)
{
    // Continue until left < right
    if(left < right)
    {
        // Find the mid point
        int mid = (left + right) / 2;

        // Divide the array into two
        sort(array, left, mid);
        sort(array, mid + 1, right);

        // Merge the two arrays
        merge(array, left, mid, right);
    }
}

int main()
{
    int myArray[] = {45, 63, 12, 76, 1, 23};

    cout << "Unsorted array: " << endl;
    for(int i = 0; i < 6; i++)
        cout << myArray[i] << " ";
    cout << endl;

    sort(myArray, 0, 5);

    cout << "Sorted array: " << endl;
    for(int i = 0; i < 6; i++)
        cout << myArray[i] << " ";
    cout << endl;

    return 0;
}