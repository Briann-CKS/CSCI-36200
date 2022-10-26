/* 
    This program creates a hash table by implementing separate chaining for collision handling. The key values are integers ranging from 10 to 99, and there are 9 entities/slots for this hash table.
    The hash function is implemented in which the program maps the first digit of the key integer as the index to access the different entities of the hash table.
    A list data structure is used to chain the values of each key to the correct slot.
    The program will first generate 1000 integers using the random seed generator to be fed to the hash table. The hash table will only append the value to one of its entities if the value is unique at the time it is being inserted.
    Then, the program will display all the entities in the hash table and prompt the user to input an integer to determine which slot/entity to be printed out more specifically.
    After that, the program will also prompt the user to input a value to be deleted from the hash table and finally print all its entities back to the user with the updated version of the hash table. 

    Data Structure: Hash Table (Separate Chaining), List, Classes
*/

#include "hash.h"
#define ARRSIZE 1000 

int main() 
{
    // For random seed generator
    srand(time(NULL));

    // Declare an array of size 1000
    int arr[ARRSIZE];

    // Generate an array of 1000 random integers 
    for (int i = 0; i < ARRSIZE; i++)
    {
        arr[i] = rand() % 90 + 10; // Restrict the range of integer to be 10 - 99
    }

    // Instantiate a new hash table of size 10
    HashTable* ht = new HashTable(10);

    // Insert each element of the array to the hash table
    for (int i = 0; i < ARRSIZE; i++)
    {
        ht->Insert(arr[i]);
    }
    ht->displayHash();

    // Get an integer input from the user for the slot of the hash table to be displayed
    try {
        int index;
        cout << "Enter an integer (1-9) for the entity slot of the hash table to be displayed: ";
        if (!(cin >> index))
            throw invalid_argument("Invalid input!");
        if (index > 9 || index < 1)
            throw out_of_range("Out of range!");

        // Display the specified slot of the hash table 
        ht->displayLine(index);
    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }

    // Get an integer key (10 - 99) from the user to delete from the hash table
    try {
        int num;
        cout << "Select a key to be deleted from the hash table: " ;
        if (!(cin >> num))
            throw invalid_argument("Invalid input!");
        if (num < 10 || num > 99 )
            throw out_of_range("Out of range!");
        ht->Delete(num);
        ht->displayHash();
    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }catch(out_of_range& e){
        cout << e.what() << endl;
    }

    return 0;
}