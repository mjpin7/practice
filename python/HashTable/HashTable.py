class HashNode:
    # CONSTRUCTOR #
    def __init__(self, value = None, key = None):
        self.value = value
        self.key = key
        self.next = None
        return

class HashTable:
    # CONSTRUCTOR #
    def __init__(self):
        self.capacity = 15
        self.size = 0
        self.table = [None] * self.capacity

    # Function to  get the hash index from a key
    #
    # @Param key            The key to find the index for 
    #
    # @Returns              The hash index of that key
    def hash(self, key):
        total = 0
        for i in range(len(key)):
            total = total + ord(key[i])
        return total % self.capacity
    
    # Function to insert into the table
    #
    # @Param key            The key of the key/value pair
    # @Param value          The value of the key/value pair
    def insert(self, key, value):
        # Get hash index
        hashIndex = self.hash(key)

        # Get the list at the hashindex
        n = self.table[hashIndex]
        prev = None

        # Traverse through the list
        while n is not None:
            prev = n
            n = n.next

        # Add to the list
        if n is None:
            n = HashNode(value=value, key=key)

            if prev is None:
                self.table[hashIndex] = n
            else:
                prev.next = n
        else:
            n.value = value
        
        print("Value %s at key %s added." % (value, key))
        self.size = self.size + 1
    
    # Function to remove a key/value pair at a given key
    #
    # @Param key            The key of the pair to remove
    def remove(self, key):
        # Get the hash index
        hashIndex = self.hash(key)

        # If the list at that index is not empty
        if self.table[hashIndex] is not None:
            n = self.table[hashIndex]
            prev = None

            # Traverse through the list until found the key
            while(n.next is not None and n.key != key):
                prev = n
                n = n.next
            
            # If found the key in the list, remove the pair
            if n.key == key:
                if prev is None:
                    self.table[hashIndex] = n.next
                else:
                    prev.next = n.next
                
            print("Element at key \"%s\" removed." % (key))
            self.size = self.size - 1
        
    # Function to get the value of a given key
    #
    # @Param key            The key to find the value of
    #
    # @Returns              The value of the given key
    def get(self, key):
        # Get hash index
        hashIndex = self.hash(key)

        n = self.table[hashIndex]
        found = False

        # Traverse through the list until the end or the key is found
        while n is not None and n.key != key:
            n = n.next

        # If the key was found, return
        if n.key == key:
            return n.value
        else:
            print("Entry with key \"%s\" not found." % (key))
            return

    # Function to print the table out
    def printTable(self):
        print()
        print()
        print("Printing table")

        for i in range(self.capacity):
            if self.table[i] is not None:
                n = self.table[i]

                while n is not None:
                    print("Key: %s Value: %s." % (n.key, n.value))
                    n = n.next
                
        print()
        print()
    
    # Function to return the size of the table
    #
    # @Returns          The size of the table
    def sizeTable(self):
        return self.size

    # Function to check if the table is empty
    #
    # @Returns          True or false, Empty or not
    def isEmpty(self):
        if self.size == 0:
            return True

        return False
    
###### TESTING ######
myTable = HashTable()
myTable.insert("Ontario", "Canada")
myTable.insert("New York", "USA")
myTable.insert("Rome", "Italy")
print("Size: %s" % (myTable.sizeTable()))
print("Element at key \"Rome\": %s" % (myTable.get("Rome")))
myTable.printTable()
myTable.remove("New York")
myTable.printTable()
            
