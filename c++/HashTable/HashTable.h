#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "HashNode.h"

using namespace std;

template<class T>
class HashTable
{
    private:
        int size;                           // Current size of the table
        int capacity;                       // The capacity of the array
        HashNode<T>** table;

    public:
        HashTable();
        ~HashTable();

        int sizeTable() { return this->size; }
        bool isEmpty() { return (this->size == 0); }
        int hash(string key);
        void insert(string key, T value);
        void remove(string key);
        T get(string key);
        void printTable();
};