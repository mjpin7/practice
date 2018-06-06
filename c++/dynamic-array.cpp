#include <iostream>
#include <new>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Function to get input and store it into the dynamic array
 * 
 * @param *arr          The array to store it in
 * @param size          The size of the array
 */
void getInput(int *arr)
{
    string input;
    getline(cin, input);

    // Tokenize the string
    stringstream ss(input);
    vector<string> tokens;
    for(string token; getline(ss, token, ' '); tokens.push_back(token));


    // Print out a summary as well as storing the converted strings into the array as ints
    cout << "You entered ";
    for(int i = 0; i < tokens.size(); i++, arr++)
    {
        cout << tokens[i] << " ";
        *arr = stoi(tokens[i]);
    }
    cout << endl;
}

/**
 * Function to print the array
 * 
 * @param *arr          Pointer to the array
 * @param size          Size of the array 
 */
void printArray(int *arr, int size)
{
    cout << "The array is ";
                
               
    for(int i = 0; i < size; i++, arr++)
    {
        cout << *arr << " ";
    }

    cout << endl << endl;
}

/**
 * Function to resize the dynamic array
 * 
 * @param *arr          The array to resize
 * @param &size         Reference to the size variable
 * 
 * @returns             The new dynamic resized array
 */
int *growArray(int *arr, int &size)
{
    // Create the new dynamic array
    int *newArr = new int[size * 2];
   
   // Copy all of the values over
    std::copy(arr, arr + size, newArr);

    // Free the memory of the old array and set the array to the new one
    delete [] arr;
    arr = newArr;

    cout << "Array of size " << size << " grew to size " << size * 2 << " and values copied over." << endl;

    // Change the size variable and return the array
    size *= 2;
    return arr;
}

int main()
{
    // Dynamically allocate array, keep track of its length as well as its beginning address
    int *array = new int[5];
    int length = 5;
    int *begin = array;
    bool end = false;
    string input;

    // Get the input for the array
    cout << "Dynamically allocated memory for an array of size 5" << endl;
    cout << "Enter the numbers seperated by spaces: ";
    getInput(array);
    array = begin;
    

    // Input loop
    int in;
    while(!end)
    {
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Print array" << endl;
        cout << "2. Grow array" << endl;
        cout << "3. Quit" << endl;
        cout << "Command: ";
        getline(cin, input);
        in = stoi(input);

        switch(in)
        {
            // Print array
            case 1:
                printArray(array, length);
                break;
            // Grow array
            case 2:
                // Get the new array
                array = growArray(array, length);

                // Set the begin reference to the new beginning
                begin = array;

                // Get the input for the newly created cells
                cout << "Enter next " << length / 2 << " values seperated by spaces: ";
                getInput(array + (length / 2));

                // Re-point the array to the beginning
                array = begin;
                break;
            // Quit
            case 3:
                // End the loop
                end = true;
                cout << "Goodbye" << endl << endl;
                break;
            // Invalid
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    return 0;
}
