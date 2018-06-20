#include <iostream>
#include "BinsarySearchTree.h"

using namespace std;

/* CONSTRUCTOR */
BinarySearchTree::BinarySearchTree()
{
    this->root = NULL;
}

/**
 * Function to call the insert function
 * 
 * @param value         The value to insert
 */
void BinarySearchTree::insert(int value)
{
    this->root = insert1(this->root, value);
}

/**
 * Function to insert a value into the binary search tree
 * 
 * @param root				The root node, or the node being passed in recursively
 * @param value				The value to insert
 * @return					The new root
 */
BinarySearchTree::Node* BinarySearchTree::insert1(Node *root, int value)
{
    // If the tree is empty, create the new node and put it at the root
    if(root == NULL)
    {
        root = new Node(value);
        return root;
    }

    // If the value is to be inserted in the left subtree
    if(value < root->value)
        root->left = insert1(root->left, value);
    // If the value is to be inserted in the right subtree
    else if(value > root->value)
        root->right = insert1(root->right, value);

    return root;
}

/**
 * Function to call the recursively implemented inorder method
 */
void BinarySearchTree::inOrder()
{
    Node *temp = root;
    inOrder1(temp);
    cout << endl;
}

/**
 * Function to recursively traverse the tree in order
 * 
 * @param root
 */
void BinarySearchTree::inOrder1(Node *root)
{
    // If the end of the tree
    if(root == NULL)
        return;

    // Visit the left child first
    inOrder1(root->left);

    // Visit the node
    cout << root->value << " ";

    // Visit the right child after
    inOrder1(root->right);
}

/**
 * Function to call the recursive delete method
 * 
 * @param value			The value to delete
 */
void BinarySearchTree::deleteValue(int value)
{
    if(isInTree(value))
    {
        root = deleteValue1(this->root, value);
        cout << "Value " << value << " deleted from the tree" << endl;
    }
    else
    {
        cout << "Value " << value << " is not in tree" << endl;
    }
}

/**
 * Function to recursively delete a given value in the tree
 * 
 * @param root			The root node
 * @param value			The value to delete
 * @return				The new root of the tree
 */
BinarySearchTree::Node* BinarySearchTree::deleteValue1(Node *root, int value)
{
    // If at the end
    if(root == NULL)
        return root;

    // If value to be deleted is in the left subtree
    if(value < root->value)
        root->left = deleteValue1(root->left, value);
    // If the value to be deleted is in the right subtree
    else if(value > root->value)
        root->right = deleteValue1(root->right, value);
    // If the value was found
    else
    {
        // Case 1 & 2: Node has only one child, or no children (is a leaf)
        if(root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
            
        // Case 3: The node has two children
        // Get the next lowest value
        root->value = minValue(root->right);

        // Delete the node that we just replaced with
        root->right = deleteValue1(root->right, root->value);
    }

    return root;
}

/**
 * Function to call the minValue method to get the min value of the tree
 * 
 * @return				The min value in the tree
 */
int BinarySearchTree::getMin()
{
    return minValue(this->root);
}

/**
 * Function to find the minimum value from a given node
 * 
 * @param node
 * @return
 */
int BinarySearchTree::minValue(Node *node)
{
    Node *curr = node;
    int min = curr->value;

    // Traverse to the left until hit a leaf
    while(curr->left != NULL)
    {
        min = curr->left->value;
        curr = curr->left;
    }

    return min;
}

/**
 * Function to call the getMax1 method to find the max value in the tree
 * 
 * @return			The max value in the tree
 */
int BinarySearchTree::getMax()
{
    return maxValue(this->root);
}

/**
 * Function to find the max value in the tree
 * 
 * @param node			The root
 * @return				The max value in the tree
 */
int BinarySearchTree::maxValue(Node *node)
{
    Node *curr = node;
    int max = curr->value;

    // Traverse to the right until hit a leaf
    while(curr->right != NULL)
    {
        max = curr->right->value;
        curr = curr->right;
    }

    return max;
}

/**
 * Function to call the getHeight1 method
 * 
 * @return				The height of the tree
 */
int BinarySearchTree::getHeight()
{
    Node *temp = root;
    return height(temp);
}

/**
 * Function to recursively find the height of the tree
 * 
 * @param root			The root
 * @return				The height of the tree
 */
int BinarySearchTree::height(Node *root)
{
    // If not a valid node, return 0
    if(root == NULL)
        return 0;

    // If a valid node, return the sum of this node plus the max of the heights of the children
    return 1 <<  max(height(root->left), height(root->right));
}

/**
 * Function to call the recursive isInTree method
 * 
 * @param value				The value to check for
 * @return					True or false, in tree or not
 */
bool BinarySearchTree::isInTree(int value)
{
    Node *temp = root;
    Node *result = isInTree1(temp, value);

    if(result != NULL)
    {
        if(result->value == value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
        return false;
}

/**
 * Function to search for a value in the tree recursively
 * 
 * @param root				The root
 * @param value				The value to search for 
 * @return					True or false, in tree or not
 */
BinarySearchTree::Node* BinarySearchTree::isInTree1(Node *root, int value)
{
    // If found or not found, return
    if(root == NULL || root->value == value)
        return root;

    if(root->value < value)
        return isInTree1(root->right, value);
    else
        return isInTree1(root->left, value);
}

/***** MAIN *****/
int main()
{
    BinarySearchTree *myBST = new BinarySearchTree();
    bool exit = false;
	
	// Input loop
	while(!exit)
	{
		cout << "What would you like to do?" << endl;
		cout << "1. Insert into BST" << endl;
		cout << "2. Delete a value in BST" << endl;
		cout << "3. Find the minimum value in the BST" << endl;
		cout << "4. Find the maximum value in the BST" << endl;
		cout << "5. Check if a value is in the BST" << endl;
		cout << "6. Print the tree in \"In-Order\" traversal" << endl;
		cout << "7. Get height of the tree" << endl;
		cout << "8. Exit" << endl;
		int input;
        cin >> input;
		cout << endl;
			
		switch(input)
		{
			case 1:
				cout << "***** INSERT VALUE *****" << endl;
				cout << "What value would you like to insert?: ";
				cin >> input;
				myBST->insert(input);
					
				cout << "Value " <<  input <<  " inserted!" << endl;
				cout << endl;
				break;
			case 2:
				cout << "***** DELETE VALUE *****" << endl;
				cout << "What value would you like to delete?: ";
				cin >> input;
				myBST->deleteValue(input);
				cout << endl;
				break;
			case 3:
				cout << "***** MINIMUM VALUE *****" << endl;
				cout << "The minimum value in the BST is " << myBST->getMin() << endl;
				cout  << endl;
				break;
			case 4:
				cout << "***** MAXIMUM VALUE *****" << endl;
				cout << "The maximum value in the BST is " << myBST->getMax() << endl;
				cout  << endl;
				break;
			case 5:
				cout << "***** SEARCH FOR VALUE *****" << endl;
				cout << "What value would you like to check for?: ";
				cin >> input;
					
				if(myBST->isInTree(input))
				{
					cout << "Value " <<  input << " is in the tree" << endl;
				}
				else
				{
					cout << "Value " << input << " is not in the tree" << endl;
				}
				cout << endl;
				break;
			case 6:
				cout << "***** PRINT IN-ORDER *****" << endl;
				myBST->inOrder();
				cout << endl;
				cout << endl;
				break;
			case 7:
				cout << "***** GET HEIGHT *****" << endl;
				cout << "The height of the tree is " <<  myBST->getHeight();
				cout << endl;
				break;
			case 8:
				cout << "***** EXIT *****" << endl;;
				cout << "Goodbye!" << endl;;
				exit = true;
				break;
			default:
				cout << "Invalid input" << endl;;
				break;
					
		}
	}
    
    return 0;
}