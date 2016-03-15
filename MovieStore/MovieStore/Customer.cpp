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

string Customer::getName() const
{
	return name;
}

void Customer::addTransaction(Transaction *trans)
{
	transactions.push_back(trans);
}
