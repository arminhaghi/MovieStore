#include "stdafx.h"
#include "InventoryTransaction.h"


InventoryTransaction::InventoryTransaction(BSTree<Movie> &argMovies)
{
	//this->movies = argMovies;
}

InventoryTransaction::~InventoryTransaction()
{
}

bool InventoryTransaction::Process()
{
	for (int i = 0; i < movies.size(); i++)
	{
		cout << movies[i]->getTitle() << ": " << movies[i]->getStock() << endl;
	}
	return false;
}

string InventoryTransaction::transactionInfo()
{
	return "";
}
