# Function to merge subarrys together
#
# @Param array              The array to merge
# @Param left               The left index
# @Param middle             The middle index
# @Param right              The right index
def merge(array, left, middle, right):
    k = left

    # Get the sizes of the two temp arrays
    size1 = (middle - left) + 1
    size2 = (right - middle)

    # Create arrays of sizes
    arr1 = [None] * size1
    arr2 = [None] * size2

    # Copy lower half of array into arr1
    for i in range(size1):
        arr1[i] = array[k]
        k += 1

    # Copy upper half of array into arr2
    for j in range(size2):
        arr2[j] = array[k]
        k += 1

    # Reset vars
    i = 0
    j = 0
    k = left

    # Loop until one of the arrays has been fully gone through
    while i < size1 and j < size2:
        # Find the smallest element of the two and copy it to the array
        if arr1[i] < arr2[j]:
            array[k] = arr1[i]
            i += 1
        else:
            array[k] = arr2[j]
            j += 1

        k += 1
    
    # Copy the rest of the array that hasn't been gone through
    while i < size1:
        array[k] = arr1[i]
        i += 1
        k += 1

    while j < size2:
        array[k] = arr2[j]
        j += 1
        k += 1

# Function to sort the array using merge sort
#
# @Param array              The array to sort
# @Param left               The left index
# @Param right              The right index
def sort(array, left, right):
    if left < right:
        middle = (left + right) // 2

        sort(array, left, middle)
        sort(array, middle + 1, right)

        merge(array, left, middle, right)


########## TESTING ##########
myArray = [45, 63, 12, 76, 1, 23]

print("Unsorted array: ")
print(myArray)

sort(myArray, 0, 5)

print("Unsorted array: ")
print(myArray)
