#include "stdafx.h"
#include "InventoryTransaction.h"


InventoryTransaction::InventoryTransaction(BSTree<Movie> &argMovies)
{
	this->movies = argMovies;
}

InventoryTransaction::~InventoryTransaction()
{
}

char InventoryTransaction::getIdentifier() const
{
	return identifier;
}

bool InventoryTransaction::Process(BSTree<Movie> movies)
{
	cout << endl << "Total inventory in store" << endl;
	cout << "====================================================================" << endl;
	movies.Display();
	cout << "====================================================================" << endl;
	return false;
}

void InventoryTransaction::printTransactionInfo(ostream &out)
{
	out << "";
}