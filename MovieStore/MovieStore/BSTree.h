#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class ItemType>
class BSTree
{
public:
	BSTree();
	~BSTree();

	bool Insert(ItemType *item);
	bool Retrieve(const ItemType &item, ItemType * &foundItem) const;
	bool RetrieveAll(const ItemType &item, vector<ItemType*> &foundItems) const;
	void Display() const;
	void Empty();
	bool isEmpty() const;

private:
	struct Node
	{
		ItemType *pItem;
		Node *right;
		Node *left;
	};
	Node *root;
	void inorder(Node *node) const;
	void deleteNode(Node *node);
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

template<class ItemType>
void BSTree<ItemType>::Display() const
{
	//PrItemType tree to cout in inorder
	Node *pNode = root;
	inorder(pNode);
}

template<class ItemType>
void BSTree<ItemType>::Empty()
{
	deleteNode(root);
	root = NULL;
}

template<class ItemType>
bool BSTree<ItemType>::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

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

