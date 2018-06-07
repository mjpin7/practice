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

        if index > self.size:
            print("Invalid index")
            return
        
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

    # Function to add a value to the beginning of the list
    #
    # @param value          The value to insert
    def push_front(self, value):

        newNode = Node(value=value)
        newNode.next = self.head

        self.head = newNode

    # Function to remove and return the first value in the list
    #
    # @returns          The value that was at the begininning
    def pop_front(self):
        temp = self.head

        # If the list is empty
        if self.empty():
            print("No values to pop off")
            return
        # If the list is not empty
        else:
            val = self.head.value
            self.head = self.head.next

            return val

    # Function to place a vlaue at the end of the list
    #
    # @Param value          The value to insert
    def push_back(self, value):
        n = Node(value=value)

        if self.empty():
            self.head = n
            return
        
        temp = self.head
        while temp.next is not None:
            temp = temp.next

        
        temp.next = n
 
    # Function to remove and return the value at the end of the list
    #
    # @Returns          The value removed at the end
    def pop_back(self):
        if self.empty():
            print("No values to pop off")
            return
        elif self.size() == 1:
            val = self.head.value
            self.head = self.head.next
            return val
        else:
            temp = self.head
            prev = temp

            while temp.next is not None:
                prev = temp
                temp = temp.next

            val = temp.value
            prev.next = None
            return val

    # Function to return the value at the beginning without removing it
    #
    # @Returns          The value at the beginning
    def front(self):
        return self.head.value

    # Function to return the value at the end without removing it
    #
    # @Returns          The value at the end
    def back(self):
        temp = self.head

        while temp.next is not None:
            temp = temp.next
        
        return temp.value

    # Function to insert a value at a given index
    #
    # @Param index          The index to insert it to
    # @Param value          The value to insert
    def insert(self, index, value):
        n = Node(value=value)
        temp = self.head

        if index > self.size:
            print("Invalid index")
            return

        # If wanting to insert to the begininning
        if index == 0:
            self.push_front(value)
            print("Value %d inserted at index %d." % (value, index))
            return

        # Else, traverse through the list
        while index > 1:
            temp = temp.next
            index -= 1
        
        n.next = temp.next
        temp.next = n

        print("Value %d inserted at index %d." % (value, index))

    # Function to delete a node at a given index
    #
    # @Param index          The node to delete
    #
    # @Returns              The value at the deleted node
    def erase(self, index):
        temp = self.head
        prev = temp

        if index > self.size:
            print("Invalid index")
            return

        # If wanting to erase the first value, call pop_front function
        if index == 0:
            return self.pop_front()
        
        # Else, traverse through the list
        while index > 0:
            prev = temp
            temp = temp.next
            index -= 1
        
        val = temp.value
        prev.next = temp.next
        temp = None
        return val


list = LinkedList()
print("Pushed 56 to front")
list.push_front(56)
print("Pushed 34 to front")
list.push_front(34)
print("Popped back %d" % (list.pop_back()))
print("Popped back %d" % (list.pop_back()))
print("Is empty", list.empty())
list.pop_back()
list.insert(0, 89)
list.insert(1, 9)
print("Front %d" % (list.front()))
print("Back %d" % (list.back()))
print("Erased index 1: %d" % (list.erase(1)))
print("Size: %d" % (list.size()))
print("Erased index 0: %d" % (list.erase(0)))
print("Size: %d" % (list.size()))


