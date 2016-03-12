#include "stdafx.h"
#include "Customer.h"


Customer::Customer()
{
	customerId = 0;
}

Customer::Customer(int & argCustomerId, string & argFirstname, string & argLastname)
{
	customerId = argCustomerId;
	customer.setFirstname(argFirstname);
	customer.setLastname(argLastname);
}

Customer::Customer(int & argCustomerId, Person & argPerson)
{
	customerId = argCustomerId;
	customer = argPerson;
}


Customer::~Customer()
{
}

int Customer::getCustomerId() const
{
	return customerId;
}

Person Customer::getPerson() const
{
	return customer;
}