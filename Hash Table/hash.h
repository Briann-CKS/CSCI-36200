#ifndef HASH_H_EXISTS
#define HASH_H_EXISTS

#include <iostream>
#include <stdlib.h>
#include <list>
#include <time.h>

using namespace std;

class HashTable 
{
    private:
        int size;
        list<int>* table; // an array of List for each slot of the hash table
    public:
        HashTable();
        HashTable(int size);
        int getSize();
        int HashFunction(int num);
        void Insert (int key);
        void Delete(int key);
        void displayHash();
        void displayLine(int index);
};

#endif
