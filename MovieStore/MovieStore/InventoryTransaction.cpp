#include "stdafx.h"
#include "InventoryTransaction.h"


InventoryTransaction::InventoryTransaction(BSTree<Movie> &argMovies)
{
	this->movies = argMovies;
}

InventoryTransaction::~InventoryTransaction()
{
}

bool InventoryTransaction::Process(BSTree<Movie> movies)
{
	
	movies.Display();
	return false;
}

string InventoryTransaction::transactionInfo()
{
	return "";
}
