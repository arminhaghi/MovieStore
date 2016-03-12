#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Customer
{
public:
	Customer();
	Customer(int &argCustomerId, string &argFirstname, string &argLastname);
	Customer(int &argCustomerId, Person &argPerson);
	~Customer();

	int getCustomerId() const;
	Person getPerson() const;

private:
	int customerId;
	Person customer;
};

