//#include "stdafx.h"
#include "HistoryTransaction.h"

HistoryTransaction::HistoryTransaction()
{
	identifier = 'H';
}

//-----------------------------------------------------------------------------
//creates an instance of the HistoryTransaction class
HistoryTransaction::HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID)
{
	identifier = 'H';
	customers = argCustomers;
	this->customerID = customerID;
}

HistoryTransaction::~HistoryTransaction()
{
}

char HistoryTransaction::getIdentifier() const
{
	return identifier;
}

//-----------------------------------------------------------------------------
// performs the transaction
bool HistoryTransaction::Process(BSTree<Movie> &movies)
{
	Customer *x = new Customer();
	x->setCustomerId(customerID);
	if (customers.Find(x, customerID))
	{
		x->displayHistory();
		return true;
	}
	else
	{
		cout << "Could not find customer " << customerID << endl;
	}
	return false;
}

//-----------------------------------------------------------------------------
//prints the action done by this object
void HistoryTransaction::printTransactionInfo(ostream &out)
{
	out << "";
}

