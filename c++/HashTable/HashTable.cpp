#include <iostream>
#include <string>
#include <cstring>
#include "HashTable.h"
#include "HashNode.h"

using namespace std;

/* CONSTRUCTOR */
template <class T>
HashNode<T>::HashNode(T value, string key)
{
    this->value = value;
    this->key = key;
    this->next = NULL;
}

/* CONSTRUCTOR */
template <class T>
HashTable<T>::HashTable()
{
     // Starting capacity of 15
    this->capacity = 15;
    // Set size to 0
    this->size = 0;
    table = new HashNode<T> *[capacity];

    // Initialize the table
    for(int i = 0; i < capacity; i++)
    {
        table[i] = NULL;
    }
}

/* DESTRUCTOR */
template <class T>
HashTable<T>::~HashTable()
{
    // Go through each index of the table
    for(int i = 0; i < capacity; i++)
    {
        HashNode<T> *n = table[i];

        // Go through the list at each index and delete the node
        while(n != NULL)
        {
            HashNode<T> *prev = n;
            n = n->next;
            delete prev;
        }
    }

    // Delete the table
    delete [] table;
}

/**
 * Function to get the hash index of a key
 * 
 * @Param key           The key to find the hash index of
 * 
 * @Returns             The hash index of that key
 */
template<class T>
int HashTable<T>::hash(string key)
{
    char ch[key.length() + 1];
    strcpy(ch, key.c_str());

    int sum = 0;
    for(int i = 0; i < key.length(); i++)
    {
        sum += ch[i];
    }

    return sum % capacity;
}

/**
 * Function to insert a key value pair into the hash table
 * 
 * @Param key           The key of the pair to insert
 * @Param value         The value of the pair to insert
 */
template <class T>
void HashTable<T>::insert(string key, T value)
{
    // Get the hash index
    int hashInd = hash(key);

    // Get the list of the correct hash index
    HashNode<T> *temp = table[hashInd];
    HashNode<T> *prev = NULL;

    // Go through the list at that index
    while(temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the last value is NULL, add new node in
    if(temp == NULL)
    {
        temp = new HashNode<T>(value, key);
        if(prev == NULL)
        {
            table[hashInd] = temp;
        }
        else
        {
            prev->next = temp;
        }
    }
    else
    {
        temp->value = value;
    }

    cout << "Value " << value << " at key " << key << " added." << endl;
    size++;
}

/**
 * Function to remove a pair with a certain key in the table (Removes the last value in the list at that key index)
 * 
 * @Param key           The key of the pair to remove
 */
template <class T>
void HashTable<T>::remove(string key)
{
    // Get the hash index of the key, and get the correct list from the table
    int hashInd = hash(key);
            
    // If there is a valid list at that index
    if(table[hashInd] != NULL)
    {
        // Get the list
        HashNode<T> *n = table[hashInd];
        HashNode<T> *prev = NULL;

        // Go through the list until found the key or at the end
        while(n->next != NULL && n->key.compare(key) != 0)
        {
            prev = n;
            n = n->next;
        }

        // If its the correct key
        if(n->key.compare(key) == 0)
        {
            // If the previous is NULL (the key found is the first one in the list), set the beginning of the list to the next
            if(prev == NULL)
            {
                HashNode<T> *nextNode = n->next;
                delete n;
                table[hashInd] = nextNode;
            }
            else
            {
                HashNode<T> *nextNode1 = n->next;
                delete n;
                prev->next = nextNode1;
            }
        }
    }

    cout << "Element at key \"" << key << "\" removed." << endl;
    size--;
}

/**
 * Function to get the value at a certain key in the map
 * 
 * @Param key           The key of the key value pair to look for
 * 
 */
template <class T>
T HashTable<T>::get(string key)
{
    // Get the hash index
    int hashInd = hash(key);

    // Get the list
    HashNode<T> *n = table[hashInd];
    bool found = false;

    // Go through the list until the key is found
    while(n != NULL && n->key.compare(key) != 0)
    {
        n = n->next;
    }

    // If the key was found, return it
    if(n->key.compare(key) == 0)
    {
        return n->value;
    }
    else
    {
        cout << "Entry with key " << key << " not found." << endl;
        return NULL;
    }
}

/**
 * Function to print the table
 */
template <class T>
void HashTable<T>::printTable()
{
    cout << endl << endl << "Printing table" << endl;;

    for(int i = 0; i < capacity; i++)
    {
        if(table[i] != NULL)
        {
            HashNode<T> *n = table[i];

            while(n != NULL)
            {
                cout << "Key: " << n->key << " Value: " << n->value << endl;
                n = n->next;
            }
        }
    }
    cout << endl << endl;
}


/***** TESTING *****/
int main()
{
    HashTable<string> *myTable = new HashTable<string>;
    myTable->insert("Ontario", "Canada");
    myTable->insert("New York", "USA");
    myTable->insert("Rome", "Italy");
    cout << "Size: " << myTable->sizeTable() << endl;
    cout << "Element at key \"Rome\": " << myTable->get("Rome") << endl;
    myTable->printTable();
    myTable->remove("New York");
    myTable->printTable();
    
    return 0;
}
