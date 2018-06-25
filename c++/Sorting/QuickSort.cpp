#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Swapping utility function */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Method for quicksort. Sorts using a random pivot to avoid the worst case complexity
 * 
 * @param array				The array to sort
 * @param low				The low index
 * @param high				The high index
 */
void sort(int *array, int low, int high)
{
    if(low == high)
        return;

    // Get the random pivot
    int pivot = array[rand() % (high - low + 1) + low];

    // Set the l and r variables
    int l = low, r = high;

    // Loop while l < r
    while(l < r)
    {
        // Move l to the right until found a value that is not less than the pivot
        while(array[l] < pivot)
            l++;

        // Move r to the left until found a value that is not greater than the pivot
        while(array[r] > pivot)
            r--;

        // Swap the two values if necessary
        if(l <= r)
        {
            swap(array[l], array[r]);
            l++;
            r--;
        }
    }

    // Partition the array
    if(low < r)
        sort(array, low, r);

    if(l < high)
        sort(array, l, high);
}

int main()
{
    // Seed random number generator
    srand((int)time(0));

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