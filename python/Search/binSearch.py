def binarySearch(list, target):
    high = len(list) - 1
    low = 0
    
    while low <= high:
        mid = (high + low) // 2

        if list[mid] == target:
            return mid
        elif target < list[mid]:
            high = mid - 1
        elif target > list[mid]:
            low = mid + 1

    return -1

def recurBinarySearch(list, target, low, high):
    mid = (low + high) // 2

    if high < low:
        return -1
    
    if target == list[mid]:
        return mid
    elif target < list[mid]:
        return recurBinarySearch(list, target, low, mid - 1)
    elif target > list[mid]:
        return recurBinarySearch(list, target, mid + 1, high)

###### TESTING ######
mylist = [3, 12, 45, 66, 123, 456, 678]

index = binarySearch(mylist, 66)

if index > 0:
    print("Number 66 found at index %d iterativelty." % index)
else:
    print("Number 66 not found in list")


index = recurBinarySearch(mylist, 456, 0, len(mylist) - 1)

if index > 0:
    print("Number 456 found at index %d recursively." % index)
else:
    print("Number 456 not found in list")

