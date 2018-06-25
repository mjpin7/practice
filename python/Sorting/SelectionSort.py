# Function to sort an array using in-place selection sort
#
# @Param array              The array to sort
def sort(array):
    # Get the size of the array
    size = len(array)

    # Loop through the array
    for i in range(size - 1):

        # Set the min to i
        min = i

        # Find the min in the right sub array
        for j in range(i, size):
            if array[j] < array[min]:
                min = j

        # Swap the values
        array[min], array[i] = array[i], array[min]

########## TEST ##########
myArray = [45, 63, 12, 76, 1, 23]

print("Unsorted array: ")
print(myArray)

sort(myArray)

print("Unsorted array: ")
print(myArray)
