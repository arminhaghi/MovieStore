//#include "stdafx.h"
#include "InventoryTransaction.h"

//-----------------------------------------------------------------------------
// creates an instance of the InventoryTransaction class
InventoryTransaction::InventoryTransaction()
{
	identifier = 'I';
}

InventoryTransaction::~InventoryTransaction()
{
}

char InventoryTransaction::getIdentifier() const
{
	return identifier;
}

//-----------------------------------------------------------------------------
// performs the transaction
bool InventoryTransaction::Process(BSTree<Movie> &movies)
{
	cout << endl << "Total inventory in store" << endl;
	cout << "====================================================================" << endl;
	movies.Display();
	cout << "====================================================================" << endl;
	return true;
}

//-----------------------------------------------------------------------------
//prints the action done by this object
void InventoryTransaction::printTransactionInfo(ostream &out)
{
	out << "";
}