#include "stdafx.h"
#include "HistoryTransaction.h"


HistoryTransaction::HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID)
{
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

void HistoryTransaction::printTransactionInfo(ostream &out)
{
	out << "";
}

