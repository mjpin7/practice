class Heap:

    # CONSTRUCTOR #
    def __init__(self, capac):
        self.capacity = capac
        self.size = 0
        self.arr = [None] * capac

    # Function to heapify from an index (sift down)
    #
    # @Param index          The index to start at
    def maxHeapify(self, index):
        left = index * 2
        right = index * 2 + 1
        largest = index

        if left <= self.size and self.arr[largest] < self.arr[left]:
            largest = left
        elif right <= self.size and self[largest] < self.arr[right]:
            largest = right

        if largest != index:
            self.arr[index], self.arr[largest] = self.arr[largest], self.arr[index]

            self.maxHeapify(largest)

    # Function for the heapSort Function. Uses root at 0 instead of 1
    #
    # @Param array              The array to heapify
    # @Param index              The index to heapify from
    # @Param size               The size of the heap
    def maxHeapify1(self, array, index, size):
        left = index * 2 + 1
        right = index * 2 + 2

        if left < size and array[left] > array[index]:
            largest = left
        else:
            largest = index

        if right < size and array[right] > array[largest]:
            largest = right

        if largest != index:
            array[largest], array[index] = array[index], array[largest]
            self.maxHeapify1(array, largest, size)

    # Function to insert a value into the heap
    #
    # @Param value              The value to insert
    def insert(self, value):
        if self.size == self.capacity - 1:
            print("Heap full, can not insert")
            return

        self.size += 1
        index = self.size
        self.arr[index] = value
        self.siftUp(index)

        print("Value %s inserted into the heap" % value)

    # Function to sift a value up at an index
    #
    # @Param index              The index to sift up
    def siftUp(self, index):

        while index != 1 and self.arr[index // 2] < self.arr[index]:
            self.arr[index // 2], self.arr[index] = self.arr[index], self.arr[index // 2]
            index //= 2

    # Function to remove and return the max value in the heap
    #
    # @Return           The max value removed
    def removeMax(self):
        if self.isEmpty():
            print("Heap empty")
            return

        if self.size == 1:
            self.size -= 1
            return self.arr[1]

        num = self.arr[1]
        self.arr[1] = self.arr[self.size]
        self.size -= 1
        self.maxHeapify(1)

        return num
    
    # Function that takes in an unsorted array and sorts in using in-place heapsort
    #
    # @Param array              The array to be sorted
    def heapSort(self, array):
        for i in range(len(array) // 2, -1, -1):
            self.maxHeapify1(array, i, len(array))

        for i in range(len(array) - 1, -1, -1):
            array[0], array[i] = array[i], array[0]
            self.maxHeapify1(array, 0, i)

    # Function to get the max value in the heap without removing it
    #
    # @Return           The max value in the heap
    def getMax(self):
        return self.arr[1]

    # Function to print the heap
    def printHeap(self):
        for i in range(1, self.size + 1):
            print(self.arr[i], end=" ")

        print()

    # Function to get the size of the heap
    #
    # @Return           The size of the heap
    def getSize(self):
        return self.size

    # Function to check if the heap is empty
    #
    # @Return           If the heap is empty or not (True/False)
    def isEmpty(self):
        return (self.size == 0)


########## TESTING ##########
myHeap = Heap(10)
myHeap.insert(45)
myHeap.insert(65)
myHeap.insert(5)
myHeap.insert(189)
myHeap.printHeap()
print("Removed the max from the heap: %d" % (myHeap.removeMax()))
myHeap.printHeap()
print("Removed the max from the heap: %d" % (myHeap.removeMax()))
myHeap.printHeap()
		
myArray = [45, 12, 67, 123, 46]
		
print("Unsorted array before heap-sort")
for i in range(len(myArray)):
    print(myArray[i], end=" ")

print()
		
myHeap.heapSort(myArray)
		
print("Sorted array after heap-sort")
for i in range(len(myArray)):
    print(myArray[i], end=" ")

print()