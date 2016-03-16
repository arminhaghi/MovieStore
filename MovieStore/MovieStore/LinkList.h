#pragma once
#ifndef LIST342_H
#define LIST342_H
#include <ostream>
#include <string>
using namespace std;

template<class ItemType>
class LinkList
{
	template<class ItemType>
	friend ostream& operator<<(ostream& theStream, const LinkList<ItemType> &linkList);

private:
	struct Node
	{
		ItemType *data;
		Node *next;
	};

	Node *head;

public:
	LinkList();
	LinkList(const LinkList &linkList);
	~LinkList();

	bool Insert(ItemType *obj);
	bool Remove(ItemType target, ItemType &result);
	bool Peek(ItemType target, ItemType *&result);
	bool isEmpty();
	void DeleteList();
};

template<class ItemType>
LinkList<ItemType>::LinkList()
{
	head = NULL;
}

template<class ItemType>
LinkList<ItemType>::LinkList(const LinkList &linkList)
{
	head = NULL;
	*this = linkList;
}

template<class ItemType>
LinkList<ItemType>::~LinkList()
{
	DeleteList();
}

template<class ItemType>
bool LinkList<ItemType>::Insert(ItemType *obj)
{
	Node *newNode;
	newNode = new Node;
	newNode->data = new ItemType(*obj);

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

template<class ItemType>
bool LinkList<ItemType>::Remove(ItemType target, ItemType &result)
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

template<class ItemType>
bool LinkList<ItemType>::Peek(ItemType target, ItemType *&result)
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

template<class ItemType>
bool LinkList<ItemType>::isEmpty()
{
	return (head == NULL);
}

template<class ItemType>
void LinkList<ItemType>::DeleteList()
{
	if (head == NULL)
	{
		return;
	}

	while (head != NULL && this != NULL)
	{
		Node *tempNode;
		ItemType *tempData;
		tempNode = head;
		tempData = head->data;
		head = head->next;
		delete tempData;
		delete tempNode;
	}

	head = NULL;
}

template<class ItemType>
ostream& operator<<(ostream& theStream, const LinkList<ItemType> &linkList)
{
	LinkList<ItemType>::Node *pNode;
	pNode = linkList.head;
	while (pNode != NULL)
	{
		theStream << *(pNode->data);
		pNode = pNode->next;
	}

	return theStream;
}

#endif