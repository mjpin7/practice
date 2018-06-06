#!/usr/bin/env python.
class Node:

    def __init__(self, value = None):
        self.value = value
        self.next = None

        return

class LinkedList:
    # Constructor
    def __init__(self):
        self.head = None

    # Function to get the size
    #
    # @returns          The size of the list
    def size(self):
        temp = self.head
        count = 0
        while temp is not None:
            count += 1
            temp = temp.next
        
        return count
    
    # Function to check if the list is empty
    #
    # @returns          True or false, empty or not
    def empty(self):
        if self.size() == 0:
            return True
        else:
            return False

    # Function to return the value at a certain index
    #
    # @param index          The index to find the value of
    #
    # @returns              The value at that index
    def value_at(self, index):
        temp = self.head
        
        # If the list is empty
        if self.size() == 0:
            print("No value to search for")
            return
        else:
            # If the index isn't valid
            if index > self.size():
                print("Index out of scope")
                return
            # If everything is valid
            else:
                # Iterate through the list
                for ind in range(index):
                    temp = temp.next

                # Return the value at that index
                return temp.value


list = LinkedList()
print(list.empty())

