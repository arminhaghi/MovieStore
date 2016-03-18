#include "stdafx.h"
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
	
	this->customerID = customerID;
	customer = new Customer();
	customer->setCustomerId(customerID);
	if (!argCustomers.Find(customer, customerID))
	{
		cout << "Could not find customer " << customerID << endl;
	}
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
	customer->displayHistory();
	return true;
}

//-----------------------------------------------------------------------------
//prints the action done by this object
void HistoryTransaction::printTransactionInfo(ostream &out)
{
	out << "";
}

