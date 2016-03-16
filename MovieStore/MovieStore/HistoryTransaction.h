#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"
#include "HashTable.h"

class HistoryTransaction : public Transaction
{
public:
	HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID);
	~HistoryTransaction();
	bool Process();

private:
	HashTable<Customer> customers;
	int customerID;
};

