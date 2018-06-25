import random

# Function to sort an array using in-place Quick sort with a random pivot
#
# @Param array              The array to sort
# @Param low                The low index
# @Param high               The high index
def sort(array, low, high):
    if low == high:
        return

    # Get the l and r index as well as get a random pivot
    l = low
    r = high
    randIndex = random.randint(low, high + 1)
    pivot = array[randIndex]

    while l < r:

        # Move l to the right until found a value that is not less than pivot
        while array[l] < pivot:
            l += 1

        # Move r to the left until found a value that is not greater than pivot
        while array[r] > pivot:
            r -= 1

        # Swap values if necessary
        if l <= r:
            array[l], array[r] = array[r], array[l]
            l += 1
            r -= 1

    # Partition the array
    if low < r:
        sort(array, low, r)

    if l < high:
        sort(array, l, high)


########## TESTING ##########
myArray = [45, 63, 12, 76, 1, 23]

print("Unsorted array: ")
print(myArray)

sort(myArray, 0, 5)

print("Unsorted array: ")
print(myArray)