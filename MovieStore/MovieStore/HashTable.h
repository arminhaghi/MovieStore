// ---------------------- HashTable<T> Header --------------------------
// Kyle Burney, Wilson Gautama, Armin  Haghi, Benjamin Porter, Maryam Zare 
// CSS 343 A
// Created February 24, 2016
// Modified 2/29/2016
// ---------------------------------------------------------------------------
// Templatized HashTable class. Calculates the hashcode based off a string
// that is passed in along with a pointer to the object that is to be stored.
// Uses the closed hashing format of hashtables.
// ---------------------------------------------------------------------------
#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "LinkList.h"
#include <string>
#include <algorithm>
using namespace std;

// size of the array of LinkedLists
const int TABLE_SIZE = 1000;

template <class ItemType>
class HashTable
{
public:
	// creates instances of HashTable objects
	HashTable();
	~HashTable();

	// inserts an item into the table
	void Insert(ItemType *item, int key);

	// finds an item in the table and stores it in item
	bool Find(ItemType *&item, int key) const;

private:
	// array of LinkedLists
	LinkList<ItemType> *table;

	// the function for determining where an item gets inserted
	int hash(int key) const;
};

//-----------------------------------------------------------------------------
// creates instances of HashTable objects
template <class ItemType>
HashTable<ItemType>::HashTable()
{
	table = new LinkList<ItemType>[TABLE_SIZE];
}

template <class ItemType>
HashTable<ItemType>::~HashTable()
{
	delete[] table;
	table = NULL;
}

//-----------------------------------------------------------------------------
// inserts an item into the table
template <class ItemType>
void HashTable<ItemType>::Insert(ItemType *item, int key)
{
	table[hash(key)].Insert(item);
}

//-----------------------------------------------------------------------------
// finds an item in the table and stores it in item
template <class ItemType>
bool HashTable<ItemType>::Find(ItemType *&item, int key) const
{
	ItemType *oldItem = item;
	bool result = table[hash(key)].Peek(*item, item);
	delete oldItem;
	return result;
}

//-----------------------------------------------------------------------------
// the function for determining where an item gets inserted
template <class ItemType>
int HashTable<ItemType>::hash(int key) const
{
	return key % 1000;
}

#endif