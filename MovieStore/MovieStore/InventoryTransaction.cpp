#include "stdafx.h"
#include "InventoryTransaction.h"

//-----------------------------------------------------------------------------
// creates an instance of the InventoryTransaction class
InventoryTransaction::InventoryTransaction(BSTree<Movie> &argMovies)
{
	identifier = 'I';
	this->movies = argMovies;
}

InventoryTransaction::~InventoryTransaction()
{
	identifier = 'I';
}

char InventoryTransaction::getIdentifier() const
{
	return identifier;
}

//-----------------------------------------------------------------------------
// performs the transaction
bool InventoryTransaction::Process(BSTree<Movie> movies)
{
	cout << endl << "Total inventory in store" << endl;
	cout << "====================================================================" << endl;
	movies.Display();
	cout << "====================================================================" << endl;
	return false;
}

//-----------------------------------------------------------------------------
//prints the action done by this object
void InventoryTransaction::printTransactionInfo(ostream &out)
{
	out << "";
}