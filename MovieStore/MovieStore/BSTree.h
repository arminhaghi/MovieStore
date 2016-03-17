/*
A BSTree object holds a Binary Search Tree

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include <vector>
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
// BSTree: a tree filled with nodes containing ItemType data
//
// Implementation and assumptions:
//
// -- Each node has data, and left and right children
// -- every nodes left child is of less value than it is
// -- every nodes right child is of greater value than it is

template<class ItemType>
class BSTree
{
public:
	BSTree();
	~BSTree();

	//inserts an object into the tree
	bool Insert(ItemType *item);
	
	// retrievs the first occurence of an object in the tree
	bool Retrieve(const ItemType &item, ItemType * &foundItem) const;
	
	// retrieves all occurences of an object in the tree
	bool RetrieveAll(const ItemType &item, vector<ItemType*> &foundItems) const;
	
	// does an in-order traversal of the tree
	void Display() const;

	// deletes all nodes from the tree
	void Empty();

	// returns true if there are no nodes in the tree
	bool isEmpty() const;

private:
	struct Node
	{
		// pointer to the data object
		ItemType *pItem;

		// right subtree pointer
		Node *right;

		// left subtree pointer
		Node *left;
	};
	// top node in the tree
	Node *root;

	// helper function for Display to print tree in-order
	void inorder(Node *node) const;

	// used to delete a node from the tree
	void deleteNode(Node *node);

	// used to delete an object from the tree
	void removeNode(ItemType *item) const;
};

template<class ItemType>
BSTree<ItemType>::BSTree()
{
	root = NULL;
}

template<class ItemType>
BSTree<ItemType>::~BSTree()
{
	Empty();
}

//inserts an object into the tree
template<class ItemType>
bool BSTree<ItemType>::Insert(ItemType * item)
{
	if (item != NULL)
	{
		ItemType *foundItem;
		if (Retrieve(*item, foundItem) == true)
		{
			cerr << "ERROR: Duplicate, insertion refused." << endl;
			return false;
		}

		Node* pNode;
		pNode = new Node();
		pNode->pItem = item;
		pNode->left = NULL;
		pNode->right = NULL;

		if (isEmpty())
		{
			root = pNode;

			return true;
		}

		Node* start;
		start = root;

		while (true)
		{
			if (*(item) < *(start->pItem))
			{
				if (start->left == NULL)
				{
					start->left = pNode;
					return true;
				}
				start = start->left;
			}
			else
			{
				if (start->right == NULL)
				{
					start->right = pNode;
					return true;
				}
				start = start->right;
			}
		}

		return true;
	}
	return false;
}

// retrievs the first occurence of an object in the tree
template<class ItemType>
bool BSTree<ItemType>::Retrieve(const ItemType &item, ItemType * &foundItem) const
{
	if (isEmpty())
	{
		return false;
	}

	Node* start;
	start = root;
	if (item == *(start->pItem))
	{
		foundItem = start->pItem;
		return true;
	}

	while (true)
	{
		if (start == NULL)
		{
			return false;
		}

		if (item == *(start->pItem))
		{
			foundItem = start->pItem;
			return true;
		}
		if (item < *(start->pItem))
		{
			start = start->left;
		}
		else
		{
			start = start->right;
		}
	}
}

// retrieves all occurences of an object in the tree
// Extra function for to Handle Clasic Movie with Multiple Actors
template<class ItemType>
bool BSTree<ItemType>::RetrieveAll(const ItemType &item, vector<ItemType*>  &foundItems) const
{
	bool result = false;
	if (isEmpty())
	{
		return false;
	}

	Node* start;
	start = root;
	if (item == *(start->pItem))
	{
		foundItems.push_back(start->pItem);
		result = true;
	}

	while (true)
	{
		if (start == NULL)
		{
			break;
		}

		if (item == *(start->pItem))
		{
			foundItems.push_back(start->pItem);
			result = true;
		}
		if (item < *(start->pItem))
		{
			start = start->left;
		}
		else
		{
			start = start->right;
		}
	}

	return result;
}

// does an in-order traversal of the tree
template<class ItemType>
void BSTree<ItemType>::Display() const
{
	//PrItemType tree to cout in inorder
	Node *pNode = root;
	inorder(pNode);
}

// deletes all nodes from the tree
template<class ItemType>
void BSTree<ItemType>::Empty()
{
	deleteNode(root);
	root = NULL;
}

// returns true if there are no nodes in the tree
template<class ItemType>
bool BSTree<ItemType>::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

// helper function for Display to print tree in-order
template<class ItemType>
void BSTree<ItemType>::inorder(Node * node) const
{
	if (node)
	{
		
		inorder(node->left);
		cout << *(node->pItem);
		inorder(node->right);
	}
}

// used to delete a node from the tree
template<class ItemType>
void BSTree<ItemType>::deleteNode(Node * node)
{
	if (node != NULL)
	{
		deleteNode(node->left);
		deleteNode(node->right);
		/*delete node;
		if (node != NULL)
		{
			if (node->left != NULL)
				node->left = NULL;
			if (node->right != NULL)
				node->right = NULL;
			if (node->pItem != NULL)
				node->pItem = NULL;*/
		node = NULL;
		//}
	}
}

// used to delete an object from the tree
template<class ItemType>
void BSTree<ItemType>::removeNode(ItemType * item) const
{
	if (item)
	{
		//preorder(node->left);
		if (root != NULL)
		{

		}
	}
}

