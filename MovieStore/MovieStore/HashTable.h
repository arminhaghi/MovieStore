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

template <typename HashItemType>
class HashTable
{
public:
	// creates instances of HashTable objects
	HashTable();
	~HashTable();

	// inserts an item into the table
	void Insert(HashItemType *item, int key);

	// finds an item in the table and stores it in item
	bool Find(HashItemType *&item, int key) const;

	void Clear();

private:
	// vector of HashItemType pointers
	vector<HashItemType*> table[TABLE_SIZE];

	// the function for determining where an item gets inserted
	int hash(int key) const;
};

//-----------------------------------------------------------------------------
// creates instances of HashTable objects
template <typename HashItemType>
HashTable<HashItemType>::HashTable()
{
}

template <typename HashItemType>
HashTable<HashItemType>::~HashTable()
{
	Clear();
}

//-----------------------------------------------------------------------------
// inserts an item into the table
template <typename HashItemType>
void HashTable<HashItemType>::Insert(HashItemType *item, int key)
{
	table[hash(key)].push_back(item);
}

//-----------------------------------------------------------------------------
// finds an item in the table and stores it in item
template <typename HashItemType>
bool HashTable<HashItemType>::Find(HashItemType *&item, int key) const
{
	HashItemType *oldItem = item;
	bool result = false;
	for (int i = 0; i < table[hash(key)].size(); i++)
	{
		if (*table[hash(key)].at(i) == *item)
		{
			item = table[hash(key)].at(i);
			result = true;
		}
	}
	delete oldItem;
	return result;
}

template<typename HashItemType>
void HashTable<HashItemType>::Clear()
{
	for (int i = TABLE_SIZE - 1; i >= 0; i--)
	{
		for (int j = table[i].size() - 1; j >= 0; j--)
		{
			if (table[i].at(j) != NULL)
			{
				delete table[i].at(j);
			}
		}
	}
}

//-----------------------------------------------------------------------------
// the function for determining where an item gets inserted
template <typename HashItemType>
int HashTable<HashItemType>::hash(int key) const
{
	return key % 1000;
}

#endif