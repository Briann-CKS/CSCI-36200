/*  
    This program creates a binary search tree (BST) by implementing a divide-and-conquer recursive algorithm based on a user-defined length and array. 
    The BST created by the program will be as balanced as possible, depending on the array length.
    3 different sorting algorithms have been implemented to sort the array before building the BST (Insertion Sort, Bubble Sort, and Selection Sort).  
    Next, the program builds the BST and displays the result in 3 different orders: Pre-Order, In-Order, and Post-Order. 
    Finally, the program looks for the user-defined, k-th smallest element in the BST and outputs the result to the user.
*/

#include <iostream>
#include "node.h"

using namespace std;

// Function declaration for printing BST with pre-order, in-order, and post-order traversal
void preorderBST(Node* node);
void inorderBST(Node* node);
void postorderBST(Node* node);

// Function declaration for sorting a user-defined array
int* sortArray(int* arr, int n);

// Function declaration for the recursive BST algorithm
Node* BST(int arr[], int left, int right);

// Function declaration for visual representation of BST
void printBT(const Node* node);
void printBT(const string& prefix, const Node* node, bool isLeft);

int main()
{
    // Prompt user to define array size and array elements for the BST 
    int n, temp, k;
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
    
    // Sort the user-defined array by calling the sortedArray function
    int* sortedArray = sortArray(arrPtr, n);

    // Call the recursive BST function and return the root node of the BST 
    Node* root = BST(sortedArray, 0, size-1); 

    // Print the BST in Pre-order, In-order, and Post-order traversal
    cout << "\nThe binary search tree in Pre-order traversal is:\n";
    preorderBST(root);  
    cout << "\nThe binary search tree in In-order traversal is:\n";
    inorderBST(root); 
    cout << "\nThe binary search tree in Post-order traversal is:\n";
    postorderBST(root); 
    cout << endl;

    // pass the root node of your binary tree
    cout << "\nVisual representation of BST:\n" << endl;
    printBT(root);

    // Prompt the user to define integer k
    cout << "\nPlease enter an integer k to find the k-th smallest element: ";
    cin >> k;

    // Check if k is a positive integer that does not exceed the array size
    if (k > n || k < 0)
    {
        cout << "Invalid integer input k!" << endl;
    }
    else
    {
        // Integer k is the index of the k-th element in the sorted array
        int answer = sortedArray[k-1];
        cout << "The " << k << "-th smallest element in the BST is " << answer << ".\n" << endl;
    }

    return 0;
}

// Function initialization for the recursive BST algorithm
Node* BST(int arr[], int left, int right)
{
    // Base case: if the left index is greater than right index, the current node does not have a child node
    if (left > right)
        return NULL;

    // Evaluate the middle index of the subarray to divide the subtree into half and conquer recursively
    int middle = (left + right)/2;

    // Set the middle element of the subarray as the value of the current node 
    Node* subtree = new Node(arr[middle]);

    // Recursively call the BST function to determine the left and right node of current subtree 
    subtree->left = BST(arr, left, middle-1);
    subtree->right = BST(arr, middle+1, right);

    return subtree;
}

// Pre-order Traversal: root node -> left node -> right node
void preorderBST(Node* node)
{
    if (node == NULL)
        return;
    cout << node->value << " ";
    preorderBST(node->left);
    preorderBST(node->right);
}

// In-order Traversal: left node -> root node -> right node
void inorderBST(Node* node)
{
    if (node == NULL)
        return;
    inorderBST(node->left);
    cout << node->value << " ";
    inorderBST(node->right);
}

// Post-order Traversal: left node -> right node -> root node
void postorderBST(Node* node)
{
    if (node == NULL)
        return;
    postorderBST(node->left);
    postorderBST(node->right);
    cout << node->value << " ";
}

// Function declaration for sorting the user-defined array using either Insertion sort, Bubble sort, or Selection sort
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

// Function initialization for visual representation of BST
void printBT(const string& prefix, const Node* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << node->value << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}
