#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
class HashNode
{
    public:
        T value;
        string key;
        HashNode *next;

        HashNode(T value, string key);
};