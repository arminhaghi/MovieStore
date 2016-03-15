#pragma once
#include <string>
#include "Transaction.h"
#include <vector>
using namespace std;

class Customer
{
public:
	Customer();
	Customer(const int &argCustomerId,  const string &argName);
	~Customer();

	bool operator<(const Customer &customer) const;
	bool operator>(const Customer &customer) const;
	bool operator==(const Customer &customer) const;

	int getCustomerId() const;
	string getName() const;
	void addTransaction(Transaction *trans);

private:
	int customerId;
	string name;
	vector<Transaction*> transactions;
};

