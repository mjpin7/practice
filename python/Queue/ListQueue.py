#!/usr/bin/env python.
## PYTHON3
class Node:
    
    # CONSTRUCTOR
    def __init__(self, value = None):
        self.value = value
        self.next = None
        return

class ListQueue:

    # CONSTRUCTOR
    def __init__(self):
        self.first = self.last = None
        return

    # Function to add a value to the end of the queue
    #
    # @Param value          The value to insert
    def enqueue(self, value):
        newNode = Node(value=value)

        if self.empty():
            self.first = self.last = newNode
            print("Enqueue'd %s" % (value))
            return
        
        self.last.next = newNode
        self.last = newNode
        return

    # Function to remove and return the next item in the queue
    #
    # @Return           The first item in the queue
    def dequeue(self):
        if self.empty():
            return None

        temp = self.first
        self.first = self.first.next

        if self.first is None:
            self.last = None

        return temp.value
    
    # Function to check if the queue is empty
    #
    # @Return           True or false, empty or not
    def empty(self):
        if self.first is None:
            return True

        return False

    # Function to print the queue
    def printQueue(self):
        temp = self.first
        print("The queue is: ")
        while temp is not None:
            print("%s " % (temp.value))
            temp = temp.next
        
        return

### TESTING ###
myQueue = ListQueue()
print(myQueue.empty())
myQueue.enqueue(67)
myQueue.enqueue(79)
myQueue.printQueue()
myQueue.enqueue(9)
myQueue.printQueue()
print("Dequeue'd %s" % (myQueue.dequeue()))
myQueue.printQueue()
