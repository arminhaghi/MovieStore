#pragma once
#include "Transaction.h"
#include "Customer.h"

class ReturnTransaction : public Transaction
{
public:
	ReturnTransaction();
	ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieName);
	~ReturnTransaction();

	bool Process(BSTree<Movie> movies);
	void printTransactionInfo(ostream &out);
	

private:
	Customer* customer;
	string movie;
};

