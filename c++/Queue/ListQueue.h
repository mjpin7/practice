#pragma once

template <class T>
class ListQueue
{
    /**
     * Struct for the nodes
     */
    struct Node{
        T value;          // Value in the node
        Node *next;         // Pointer to the next node in the list
    };

    private:
        Node *first, *last;
    
    public:
        ListQueue();
        ~ListQueue();
        void enqueue(T value);
        T dequeue();
        bool empty();
        void printQueue();
};