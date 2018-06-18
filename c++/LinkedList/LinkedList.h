#pragma once

class LinkedList
{
    /**
     * Struct for a node, of which the list is consisted of
     */
    struct Node
    {
        int value;          // Value in the node
        Node *next;         // Pointer to the next node in the list
    };

    private:
        Node *head;

    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool empty();
        int value_at(int index);
        void push_front(int value);
        int pop_front();
        void push_back(int value);
        int pop_back();
        int front();
        int back();
        void insert(int index, int value);
        int erase(int index);
};