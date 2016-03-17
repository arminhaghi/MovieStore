#include "stdafx.h"
#include "HistoryTransaction.h"

//-----------------------------------------------------------------------------
//creates an instance of the HistoryTransaction class
HistoryTransaction::HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID)
{
	customers = argCustomers;
	this->customerID = customerID;
}

HistoryTransaction::~HistoryTransaction()
{
}

//-----------------------------------------------------------------------------
// performs the transaction
bool HistoryTransaction::Process(BSTree<Movie> movies)
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

