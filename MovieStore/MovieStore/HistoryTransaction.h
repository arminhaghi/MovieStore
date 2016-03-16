#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "HashTable.h"

class HistoryTransaction : public Transaction
{
public:
	HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID);
	~HistoryTransaction();
	bool Process(BSTree<Movie> movies);
	string transactionInfo();

private:
	HashTable<Customer> customers;
	int customerID;
};

