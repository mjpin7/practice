#include <iostream>

using namespace std;

/**
 * Function to iteratively do binary search on a sorted array
 * 
 * @Param arr[]             The sorted array to search
 * @Param target            The number being searched for
 * @Param size              The size of the array
 * 
 * @Returns                 The index if found, -1 if not found
 */
int binarySearch(int arr[], int target, int size)
{
    int low = 0, high = size - 1, mid;

    // Go until low <= high
    while(low <= high)
    {
        // Get the middle value
        mid = (low + high) / 2;

        // If its the value looking for return
        if(arr[mid] == target)
        {
            return mid;
        }
        // If the value at this index is smaller than the target, search upper half of array
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        // If the value at this index is larger than the target, search lower half of array
        else if(arr[mid] > target)
        {
            high = mid - 1;
        }
    }

    return -1;
}

/**
 * Function to recursively binary search a sorted array
 * 
 * @Param arr[]             The array to look in
 * @Param target            The target to look for
 * @Param high              The high index of the section to look in
 * @Param low               The low index of the section to look in
 * 
 * @Returns                 The index if found, -1 if not found
 */
int recurBinarySearch(int arr[], int target, int high, int low)
{
    // Get the middle index
    int mid = (high + low) / 2;

    // If not found
    if(high < low)
        return -1;


    // If the target was found, return
    if(target == arr[mid])
    {
        return mid;
    }
    // If the target is less than the number at index, recursively call with the high set to mid - 1
    else if(target < arr[mid])
    {
        return recurBinarySearch(arr, target, mid - 1, low);
    }
    // If the target is greater than the number at index, recursively call with the low set to mid + 1
    else if(target > arr[mid])
    {
        return recurBinarySearch(arr, target, high, mid + 1);
    }
}

int main()
{
    int myArray[] = {1, 34, 56, 67, 123, 345, 543};

    int index = binarySearch(myArray, 67, 7);

    if(index > 0)
    {
        cout << "Number 67 found at index " << index << " iteratively" << endl; 
    }
    else
    {
        cout << "Number 67 not found in the array" << endl;
    }
    
    index = recurBinarySearch(myArray, 345, 6, 0);

    if(index > 0)
    {
        cout << "Number 345 found at index " << index << " recursively" << endl; 
    }
    else
    {
        cout << "Number 345 not found in the array" << endl;
    }

    


    return 0;
}