#include "hash.h"

HashTable::HashTable(int size)
{
    this->size = size;
    this->table = new list<int>[size];
}

int HashTable::getSize()
{
    return this->size;
}

int HashTable::HashFunction(int num)
{
    return num / 10;
}

void HashTable::Insert(int key)
{
    int index = HashFunction(key);
    if (find(table[index].begin(), table[index].end(), key) == table[index].end())
        table[index].push_back(key);
}

void HashTable::Delete(int key)
{
  int index = HashFunction(key);
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++)
    if (*i == key)
      break;
  if (i != table[index].end())
    table[index].erase(i);
}

void HashTable::displayHash() {
  for (int i = 1; i < size; i++) 
  {
    cout << "List[" << i << "]:";
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
  cout << endl;
}

void HashTable::displayLine(int index){
  cout << "List[" << index << "]:";
  for (auto x : table[index])
    cout << " -> " << x;
  cout << "\n" << endl;
}