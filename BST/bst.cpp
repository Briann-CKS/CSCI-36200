#include <iostream>
#include "node.h"

using namespace std;

Node* BST(int arr[], int left, int right);
void preorderBST(Node* node);
void inorderBST(Node* node);
void postorderBST(Node* node);
int* sortArray(int* arr, int n);

int main()
{
    int n, temp;
    cout << "Please enter the size of your array to create a Binary Search Tree: ";
    cin >> n; 
    int arr[n];
    int *arrPtr = arr; 
    cout << "\nPlease enter the elements of your array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    int* sortedArray = sortArray(arrPtr, n);
    Node* root = BST(sortedArray, 0, size-1); 
    cout << "\nThe binary search tree in Pre-order traversal is:\n";
    preorderBST(root);  
    cout << "\nThe binary search tree in In-order traversal is:\n";
    inorderBST(root); 
    cout << "\nThe binary search tree in Post-order traversal is:\n";
    postorderBST(root); 
    cout << endl;
}

Node* BST(int arr[], int left, int right)
{
    if (left > right)
        return NULL;

    int middle = (left + right)/2;
    Node* subtree = new Node(arr[middle]);
    subtree->left = BST(arr, left, middle-1);
    subtree->right = BST(arr, middle+1, right);

    return subtree;
}

void preorderBST(Node* node)
{
    if (node == NULL)
        return;
    cout << node->value << " ";
    preorderBST(node->left);
    preorderBST(node->right);
}

void inorderBST(Node* node)
{
    if (node == NULL)
        return;
    inorderBST(node->left);
    cout << node->value << " ";
    inorderBST(node->right);
}

void postorderBST(Node* node)
{
    if (node == NULL)
        return;
    postorderBST(node->left);
    postorderBST(node->right);
    cout << node->value << " ";
}

int* sortArray(int* arr, int n)
{
    // Insertion sort 
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    // Bubble sort
    /*
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
    */
    
    // Selection sort
    /*
    for (int i = 0; i < n-1; i++)
    {
        int temp;
        int smallest = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        if (smallest != i)
        {
            temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
    }
    */
    return arr;
}