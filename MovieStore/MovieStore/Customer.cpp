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