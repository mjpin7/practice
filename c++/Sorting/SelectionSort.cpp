#include <iostream>

using namespace std;

/**
 * Swap function
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Function to sort an array using in-place selection sort
 * 
 * @param array				The array to sort
 * @Param size              The size of the array
 */
void sort(int *array, int size)
{
    // Loop through array
    for(int i = 0; i < size - 1; i++)
    {
        // Set the min to i
        int min = i;

        // Find the min in the right sub array
        for(int j = i + 1; j < size; j++)
        {
            if(array[j] < array[min])
                min = j;
        }

        // Swap the values
        swap(array[min], array[i]);
    }
}

int main()
{
    int myArray[] = {45, 63, 12, 76, 1, 23};

    cout << "Unsorted array: " << endl;
    for(int i = 0; i < 6; i++)
        cout << myArray[i] << " ";
    cout << endl;

    sort(myArray, 6);

    cout << "Sorted array: " << endl;
    for(int i = 0; i < 6; i++)
        cout << myArray[i] << " ";
    cout << endl;

    return 0;
}