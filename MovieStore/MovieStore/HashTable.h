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

const int TABLE_SIZE = 1000;

template <class ItemType>
class HashTable
{
public:
	HashTable();
	~HashTable();

	void Insert(ItemType *item, int key);
	bool Find(ItemType *&item, int key) const;

private:
	LinkList<ItemType> *table;
	int hash(int key) const;
};

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

template <class ItemType>
void HashTable<ItemType>::Insert(ItemType *item, int key)
{
	table[hash(key)].Insert(item);
}

template <class ItemType>
bool HashTable<ItemType>::Find(ItemType *&item, int key) const
{
	ItemType *oldItem = item;
	bool result = table[hash(key)].Peek(*item, item);
	delete oldItem;
	return result;
}

template <class ItemType>
int HashTable<ItemType>::hash(int key) const
{
	return key % 1000;
}

#endif