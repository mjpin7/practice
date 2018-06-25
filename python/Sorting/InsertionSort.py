# Function to sort an array using in-place insertion sort
#
# @Param array              The array to sort
#
#
def sort(array):
    # Get the size of the array
    size = len(array)

    # Loop through the array starting at 1
    for i in range(1, size):
        # Store the value at the index and set j
        value = array[i]
        j = i - 1

        # Move all the values over that are greater than "value"
        while j >= 0 and array[j] > value:
            array[j + 1] = array[j]
            j = j - 1

        # Place tha value in the spot
        array[j + 1] = value

########## TESTING ##########
myArray = [45, 63, 12, 76, 1, 23]

print("Unsorted array: ")
print(myArray)

sort(myArray)

print("Unsorted array: ")
print(myArray)