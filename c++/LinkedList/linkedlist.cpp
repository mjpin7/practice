#include <iostream>
#include "LinkedList.h"

using namespace std;

/* CONSTRUCTOR */
LinkedList::LinkedList()
{
    head = NULL;
}

/* DESTRUCTOR */
LinkedList::~LinkedList()
{
    Node *x = head;

    // Loop to delete all elements
    while(x != NULL)
    {
        Node *n = x;        // Node to delete
        x = x->next;
        delete n;
    }
}

/**
 * Member function to find the size of the list
 * 
 * @returns         The size of the list
 */
int LinkedList::size()
{
    Node *n = head;
    int size = 0;

    // Loop to get size
    while(n != NULL)
    {
        size++;
        n = n->next;
    }

    return(size);
}

/**
 * Member function to return whether the list is empty
 * 
 * @returns         True or false, empty or not
 */
bool LinkedList::empty()
{
     if(head == NULL)
        return true;
            
    return false;
}

/**
 * Member function to get the value at a certain index
 * 
 * @param index         The index to look in
 * 
 * @returns             The value at that index
 */
int LinkedList::value_at(int index)
{
    if(empty())
    {
        cout << "No values to retrieve" << endl;
        return -1;
    }

    if(index > size())
    {
        cout << "Index " << index << " out of scope." << endl;
        return -1;
    }

    Node *n = head;
    for(int i = 0; i < index; i++)
        n = n->next;

    return n->value;
}

/**
 * Member function to push a value to the beginning of the list
 * 
 * @param value         The value to insert
 */
void LinkedList::push_front(int value)
{
    Node *n = new Node();
    n->value = value;
    n->next = head;

    head = n;
}

/**
 * Member function to remove and return the value at the front of the list
 * 
 * @returns         The removed value at the front
 */
int LinkedList::pop_front()
{
    Node *n = head;
    if(empty())
    {
        cout << "No values to pop" << endl;
        return -1;
    }
    else if(size() == 1)
    {
        int val = head->value;
        delete head;

        head = NULL;
        return val;
    }
    else
    {
        int val = n->value;

        head = n->next;
        delete n;

        return val;
    }
}

/**
 * Member function to add a value to the end of the list
 * 
 * @param value         The value to add
 */
void LinkedList::push_back(int value)
{
    Node *n = head;

    // New node to insert
    Node *insert = new Node();
    insert->value = value;

    // Get to the end of the list
    while(n->next != NULL)
        n = n->next;

    // Insert the new node at the end
    n->next = insert;
}

/**
 * Member function to remove and return the last value in the list
 * 
 * @returns         The last value of the list
 */
int LinkedList::pop_back()
{
    if(empty())
    {
        cout << "No values to pop" << endl;
        return -1;
    }
    else if(size() == 1)
    {
        int val = head->value;
        delete head;
                
        head = NULL;
        return val;
    }
    else
    {
        Node *n = head;

         // Get to the end
        while(n->next != NULL)
        {
            n = n->next;
        }
                    
        // Get the value
        int value = n->value;

        // Delete the last value
        //prev->next = NULL;
        delete n;

        return(value);
    }
}

/**
 * Member function to get the first value without removing it
 * 
 * @returns         The value at the front
 */
int LinkedList::front()
{
    if(empty())
    {
        cout << "No values to pop" << endl;
        return -1;
    }

    return head->value;
}

/**
 * Member function to get the last value without removing it
 * 
 * @returns         The value at the end
 */
int LinkedList::back()
{
    if(empty())
    {
         cout << "No values to pop" << endl;
        return -1;
    }

    Node *n = head;

    while(n->next != NULL)
         n = n->next;

    return n->value;
}

/**
 * Member function to insert a value at the given index
 * 
 * @param index         The index to add it to
 * @param value         The value to add to that index
 */
void LinkedList::insert(int index, int value)
{
    Node *n = head;

    for(int i = 1; i < index; i++)
        n = n->next;
            
    Node *nextNode = n->next;

    Node *newNode = new Node();         // Create new node
    newNode->value = value;             // Set new nodes value to value
    newNode->next = nextNode;           // Set the new nodes next to the next node
    n->next = newNode;                  // Place the new node after the correct node
}

/**
 * Member function to delete the value at a given index
 * 
 * @param index         The index to delete
 * 
 * @returns             The value at that index
 */
int LinkedList::erase(int index)
{
    if(empty())
    {
        cout << "No values to erase" << endl;
        return -1;
    }
    else if(size() == 1)
    {
        int val = head->value;
        delete head;

        head = NULL;
        return val;
    }
    else
    {
        // If its the head
        if(index == 0)
        {
            int val = pop_front();
            return val;
        }
        // If its the tail
        else if(index == size())
        {
            int val = pop_back();
            return val;
        }

        Node *n = head;
        Node *prev = n;

        // Go through the list, storing the node previous to the current
        for(int i = 0; i < index; i++)
        {
            prev = n;
            n = n->next;
        }

        int val = n->value;

        // Point the nodes correctly and delete the old node
        prev->next = n->next;
        delete n;

        return val;
    }
}

int main()
{
    LinkedList list1;
    cout << "\t\tTEST" << endl << endl;
    cout << "Pushed 2 to front" << endl;
    list1.push_front(2);

    cout << "Pushed 23 to front" << endl;
    list1.push_front(23);

    cout << "Size: " << list1.size() << endl;
    cout << "Popped front: " << list1.pop_front() << endl;
    cout << "Inserted 57 at index \"1\" "<< endl;
    list1.insert(1, 57);
    cout << "Value at index \"1\": " << list1.value_at(1) << endl;
    cout << "Popped front: " << list1.pop_front() << endl;
    cout << "Back: " << list1.back() << endl;
    cout << "Pushed 78 to back" << endl;
    list1.push_back(78);

    cout << "Erased node at index \"1\": " << list1.erase(1) << endl;

    cout << "Popped back: " << list1.pop_back() << endl;
    cout << "Size: " << list1.size() << endl;
    
    

    return 0;
}