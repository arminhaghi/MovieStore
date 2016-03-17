#include "stdafx.h"
#include "Customer.h"


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
}

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

int Customer::getCustomerId() const
{
	return customerId;
}

void Customer::setCustomerId(int id)
{
	customerId = id;
}

string Customer::getName() const
{
	return name;
}

void Customer::addTransaction(Transaction *trans)
{
	transactions.push_back(trans);
}

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
