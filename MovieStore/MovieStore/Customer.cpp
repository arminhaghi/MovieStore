#include "stdafx.h"
#include "Customer.h"

//-----------------------------------------------------------------------------
// creates an instance of the Customer class
Customer::Customer()
{
	customerId = 0;
}

Customer::Customer(const int & argCustomerId, const string & argName)
{
	customerId = argCustomerId;
	name = argName;
}

Customer::~Customer()
{
	for (int i = transactions.size() - 1; i >= 0; i--)
	{
		delete transactions.at(i);
	}
}

//-----------------------------------------------------------------------------
// Operator Functions
bool Customer::operator<(const Customer &customer) const
{
	return customerId < customer.customerId;
}

bool Customer::operator>(const Customer &customer) const
{
	return customerId > customer.customerId;
}

bool Customer::operator==(const Customer &customer) const
{
	return customerId == customer.customerId;
}

//-----------------------------------------------------------------------------
// gets the ID of the customer
int Customer::getCustomerId() const
{
	return customerId;
}

//-----------------------------------------------------------------------------
// sets the ID of the customer
void Customer::setCustomerId(int id)
{
	customerId = id;
}

//-----------------------------------------------------------------------------
// gets the name of the customer
string Customer::getName() const
{
	return name;
}

//-----------------------------------------------------------------------------
// adds a transaction to the Customer's collection of Transactions
void Customer::addTransaction(Transaction *trans)
{
	transactions.push_back(trans);
}

//-----------------------------------------------------------------------------
// displays the history of Transactions done by the Customer
void Customer::displayHistory() const
{
	cout << endl << "Transaction history for customer " << customerId << endl;
	cout << "====================================================================" << endl;
	for (int i = 0; i < transactions.size(); i++)
	{
		cout << *transactions[i] << endl;
	}
	cout << "====================================================================" << endl;
}

bool Customer::isAllowedToReturn(Movie * movie) const
{
	int borrowed = 0;
	int returned = 0;

	for (int i = 0; i < transactions.size(); i++)
	{
		if (transactions.at(i)->getIdentifier() == 'B')
		{
			if (transactions.at(i)->getMovie() == movie)
			{
				borrowed++;
			}
		}
		else if (transactions.at(i)->getIdentifier() == 'R')
		{
			if (transactions.at(i)->getMovie() == movie)
			{
				returned++;
			}
		}
	}

	return borrowed > returned;
}
