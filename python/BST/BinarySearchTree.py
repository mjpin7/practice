class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        return

class BinarySearchTree:

    def __init__(self):
        self.root = None

    def insert(self, value):
        self.root = self.__insert(self.root, value)

    def __insert(self, node, value):
        if node is None:
            node = Node(value)
            return node

        if value < node.value:
            node.left = self.__insert(node.left, value)
        elif value > node.value:
            node.right = self.__insert(node.right, value)

        return node
    
    def inOrder(self):
        self.__inOrder(self.root)
        print()
    
    def __inOrder(self, node):
        if node is None:
            return

        self.__inOrder(node.left)

        print("%d" % node.value, end = " ")

        self.__inOrder(node.right)

    def delete(self, value):
        if self.isInTree(value):
            self.root = self.__delete(self.root, value)
            print("Value %d deleted from tree" % (value))
        else:
            print("Value %d not found in tree" % (value))

    def __delete(self, node, value):
        if node is None:
            return node

        if value < node.value:
            root.left = self.__delete(root.left, value)
        elif value > node.value:
            root.right = self.__delete(root.right, value)
        else:
            # Case 1 & 2: 1 or no children
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            
            # Case 3: Two children
            node.value = self.minValue(node.right)

            node.right = self.__delete(node.right, node.value)

        return node

    def getMin(self):
        return self.__minValue(self.root)
    
    def __minValue(self, node):
        min = node.value

        while node.left is not None:
            min = node.left.value
            node = node.left
        
        return min
    
    def getMax(self):
        return self.__maxValue(self.root)

    def __maxValue(self, node):
        max = node.value

        while node.right is not None:
            max = node.right.value
            node = node.right

        return max

    def isInTree(self, value):
        verdict = self.__isInTree(self.root, value)

        if verdict is not None:
            if verdict.value == value:
                return True
            else:
                return False
        else:
            return False

    def __isInTree(self, node, value):
        if node is None or node.value == value:
            return node

        if value < node.value:
            return self.__isInTree(node.left, value)
        else:
            return self.__isInTree(node.right, value)

    def getHeight(self):
        return self.__heightValue(self.root)

    def __heightValue(self, node):
        if node is None:
            return 0

        return 1 + max(self.__heightValue(node.left), self.__heightValue(node.right))
        
###### TEST ######
myBST = BinarySearchTree()
end = False

while not end:
    print("What would you like to do?")
    print("1. Insert into BST")
    print("2. Delete a value in BST")
    print("3. Find the minimum value in the BST")
    print("4. Find the maximum value in the BST")
    print("5. Check if a value is in the BST")
    print("6. Print the tree in \"In-Order\" traversal")
    print("7. Get height of the tree")
    print("8. Exit")
    input1 = int(input(""))

    if input1 == 1:
        print("****** INSERT VALUE ******")
        input1 = int(input("What value would you like to insert?: "))
        myBST.insert(input1)

        print("Value %d inserted!\n" % input1)
    elif input1 == 2:
        print("****** DELETE VALUE ******")
        input1 = int(input("What value would you like to delete?: "))
        myBST.delete(input1)
        print()
    elif input1 == 3:
        print("****** MINUMUM VALUE ******")
        print("The minimum value in the BST is %d" % myBST.getMin())
        print("\n")
    elif input1 == 4:
        print("***** MAXIMUM VALUE *****")
        print("The maximum value in the BST is %d" % myBST.getMax())
        print("\n")
    elif input1 == 5:
        print("***** SEARCH FOR VALUE *****")
        input1 = int(input("What value would you like to check for?: "))

        if(myBST.isInTree(input1)):
            print("value %d is in the tree" % input1)
        else:
            print("value %d is not in the tree" % input1)
    elif input1 == 6:
        print("***** PRINT IN-ORDER *****")
        myBST.inOrder()
        print()
        print()
    elif input1 == 7:
        print("***** GET HEIGHT *****")
        print("The height of the tree is %d" % myBST.getHeight())
        print()
    elif input1 == 8:
        print("***** EXIT *****")
        print("Goodbye!")
        end = True
    else:
        print("Invalid input")
    

    