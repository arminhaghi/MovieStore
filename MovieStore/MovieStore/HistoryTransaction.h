#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "HashTable.h"

class HistoryTransaction : public Transaction
{
public:
	HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID);
	~HistoryTransaction();

	char getIdentifier() const;
	bool Process(BSTree<Movie> movies);
	void printTransactionInfo(ostream &out);

private:
	char identifier = 'H';
	HashTable<Customer> customers;
	int customerID;
};

