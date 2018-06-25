#include <iostream>

using namespace std;

/**
 * Function to sort an array using in-place Insertion sort
 * 
 * @param array				The array to sort
 * @Param size              The size of the array
 */
void sort(int *array, int size)
{
    // Loop through the array
    for(int i = 1; i < size; i++)
    {
        // Get the value at the index and set j value
        int value = array[i];
        int j = i - 1;

        // Move the elements of left side that are greater than value over one position 
        while(j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        // Insert the value once all values are moved over
        array[j + 1] = value;
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