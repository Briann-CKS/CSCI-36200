#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include <iostream>

class Node 
{
    public:
        Node* left = NULL;
        Node* right = NULL;
        int value;
        Node(int value);
};

#endif