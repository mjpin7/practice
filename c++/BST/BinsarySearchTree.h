#pragma once

class BinarySearchTree
{
    struct Node
    {
        int value;                  // Value in the node
        Node *left, *right;         // Pointer to the left and right node in the tree

        /* CONSTRUCTOR */
        Node(int val)
        {
            this->value = val;
            this->left = NULL;
            this->right = NULL;
        }
    };

    private:
    
        Node *root;                 // The root of the tree

        /* PRIVATE MEMBER FUNCTIONS */
        Node* insert1(Node *root, int value);
        void inOrder1(Node *root);
        Node* deleteValue1(Node *root, int value);
        int minValue(Node *root);
        int maxValue(Node *root);
        int height(Node *root);
        Node* isInTree1(Node *root, int value);


    public:

        /* PUBLIC MEMBER FUNCTIONS */
        BinarySearchTree();
        void insert(int value);
        void inOrder();
        void deleteValue(int value);
        int getMin();
        int getMax();
        int getHeight();
        bool isInTree(int value);
};