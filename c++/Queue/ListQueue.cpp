#include <iostream>
#include "ListQueue.h"

using namespace std;

/* CONSTRUCTOR */
template <class T>
ListQueue<T>::ListQueue()
{
    first = last = NULL;
}

/* DESTRUCTOR */
template <class T>
ListQueue<T>::~ListQueue()
{
    // Go through the list and delete the elements
    while(first != NULL)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
    last = NULL;
}

/**
 * Member function to add a node to the end of the queue
 * 
 * @Param value         The value to insert
 */
template <class T>
void ListQueue<T>::enqueue(T value)
{
    // Create the new node
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;

    // If the queue is empty, set the first and the last to the new node
    if(empty())
    {
        first = last = newNode;
        cout << "Enqueue'd " << value << endl;
        return;
    }

    // Insert the new node into the end of the queue and set the last to point to the new node
    last->next = newNode;
    last = newNode;
    cout << "Enqueue'd " << value << endl;;
    return;
}

/**
 * Member function to remove and return the value at the node in the front
 * 
 * @Return          The value in the front
 */
template <class T>
T ListQueue<T>::dequeue()
{
    // If empty
    if(empty())
    {
        return NULL;
    }

    // Set a temp variable as the front
    Node *n = first;

    // If queue size 1
    if(first == last)
    {
        first = last = NULL;
        return n->value;
    }

    // Point the front to the next
    first = first->next;
    return n->value;
}

/**
 * Member function to check if the queue is empty
 * 
 * @Return          true or false, Empty or not
 */
template <class T>
bool ListQueue<T>::empty()
{
    if(first == NULL)
    {
        return true;
    }

    return false;
}

/**
 * Member function to print the queue to the console
 */
template <class T>
void ListQueue<T>::printQueue()
{
    Node *n = first;

    cout << "The queue is: ";
    while(n != NULL)
    {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    /*** TESTING ***/
    ListQueue<int> myQueue;
    if(myQueue.empty())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    myQueue.enqueue(67);
	myQueue.enqueue(79);
	myQueue.printQueue();
	myQueue.enqueue(9);
	myQueue.printQueue();
    cout << "Dequeue'd " << myQueue.dequeue() << endl;
    myQueue.printQueue();
    return 0;
}
