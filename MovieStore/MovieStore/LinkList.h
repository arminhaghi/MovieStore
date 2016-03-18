/*
A LinkList object hold a Binary Search Tree

Author: Armin Haghi, Kyle Burney
*/

#pragma once
#ifndef LIST342_H
#define LIST342_H
#include <ostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// LinkList: a list filled with nodes containing templatized data
//
// Implementation and assumptions:
//
// -- Each node has data, and pointer to the next node

template<typename LinkItemType>
class LinkList
{
	// displays the items in the list
	/*template<typename LinkItemType>
	friend ostream& operator<<(ostream& theStream, 
	const LinkList<LinkItemType> &linkList);*/

private:
	struct Node
	{
		// pointer to data object
		LinkItemType *data;

		// pointer to next node
		Node *next;
	};

	// begining of the list
	Node *head;

public:
	//creates an instance of the LinkList class
	LinkList();
	LinkList(const LinkList &linkList);
	~LinkList();

	// inserts an item into the list
	bool Insert(LinkItemType *obj);

	// removes an item from the list
	bool Remove(LinkItemType target, LinkItemType &result);

	// checks if an item is in the list, returns true if it is,
	// and stores it in result
	bool Peek(LinkItemType target, LinkItemType *&result);

	// checks if there are no items in the list
	bool isEmpty();

	// deletes all items in the list
	void DeleteList();
};

#endif

//-----------------------------------------------------------------------------
//creates an instance of the LinkList class
template<typename LinkItemType>
LinkList<LinkItemType>::LinkList()
{
	head = NULL;
}

template<typename LinkItemType>
LinkList<LinkItemType>::LinkList(const LinkList &linkList)
{
	head = NULL;
	*this = linkList;
}

template<typename LinkItemType>
LinkList<LinkItemType>::~LinkList()
{
	DeleteList();
}

//-----------------------------------------------------------------------------
// inserts an item into the list
template<typename LinkItemType>
bool LinkList<LinkItemType>::Insert(LinkItemType *obj)
{
	Node *newNode;
	newNode = new Node;
	newNode->data = new LinkItemType(*obj);

	if (head == NULL)
	{
		newNode->next = NULL;
		head = newNode;

		return true;
	}

	if (*(head->data) == *obj)
	{
		return false;
	}
	else if (*(head->data) > *obj)
	{
		Node *tempNode;
		tempNode = head;
		head = newNode;
		newNode->next = tempNode;

		return true;
	}

	Node *prevNode;
	prevNode = head;

	while (prevNode->next != NULL)
	{
		if (*(prevNode->next->data) == *obj)
		{
			return false;
		}
		else if (*(prevNode->next->data) < *obj)
		{
			if (prevNode->next != NULL)
			{
				prevNode = prevNode->next;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	newNode->next = prevNode->next;
	prevNode->next = newNode;
	return true;
}

//-----------------------------------------------------------------------------
// removes an item from the list
template<typename LinkItemType>
bool LinkList<LinkItemType>::Remove(LinkItemType target, LinkItemType &result)
{
	Node *prevNode;
	prevNode = head;

	if (*(prevNode->data) == target)
	{
		if (head->next != NULL)
		{
			result = *(prevNode->data);
			head = head->next;
		}
		else
		{
			head = NULL;
		}
		return true;
	}

	while (prevNode->next != NULL)
	{
		if (*(prevNode->next->data) == target)
		{
			result = *(prevNode->next->data);
			prevNode->next = prevNode->next->next;
			return true;
		}
		prevNode = prevNode->next;
	}

	return false;
}

//-----------------------------------------------------------------------------
// checks if an item is in the list, returns true if it is,
// and stores it in result
template<typename LinkItemType>
bool LinkList<LinkItemType>::Peek(LinkItemType target, LinkItemType *&result)
{
	if (head == NULL)
		return false;
	Node *prevNode;
	prevNode = head;

	if (*(prevNode->data) == target)
	{
		result = (prevNode->data);
		return true;
	}

	while (prevNode->next != NULL)
	{
		if (*(prevNode->next->data) == target)
		{
			result = (prevNode->next->data);
			return true;
		}
		prevNode = prevNode->next;
	}

	return false;
}

//-----------------------------------------------------------------------------
// checks if there are no items in the list
template<typename LinkItemType>
bool LinkList<LinkItemType>::isEmpty()
{
	return (head == NULL);
}

//-----------------------------------------------------------------------------
// deletes all items in the list
template<typename LinkItemType>
void LinkList<LinkItemType>::DeleteList()
{
	if (head == NULL)
	{
		return;
	}

	while (head != NULL && this != NULL)
	{
		Node *tempNode;
		LinkItemType *tempData;
		tempNode = head;
		tempData = head->data;
		head = head->next;
		delete tempData;
		delete tempNode;
	}

	head = NULL;
}

//-----------------------------------------------------------------------------
// displays the items in the list
//template<typename LinkItemType>
//ostream& operator<<(ostream& theStream, const 
//			LinkList<LinkItemType> &linkList)
//{
//	LinkList<LinkItemType>::Node *pNode = NULL;
//	pNode = linkList.head;
//	while (pNode != NULL)
//	{
//		theStream << *(pNode->data);
//		pNode = pNode->next;
//	}
//
//	return theStream;
//}
//
