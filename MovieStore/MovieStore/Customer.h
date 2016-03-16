#pragma once
#include <string>
#include "Transaction.h"
#include <vector>
#include <iostream>
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
	void setCustomerId(int id);
	string getName() const;
	void addTransaction(Transaction *trans);
	void displayHistory() const;

private:
	int customerId;
	string name;
	vector<Transaction*> transactions;
	vector<string> history;
};