#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class ReturnTransaction : public Transaction
{
public:
	ReturnTransaction();
	ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieName);
	~ReturnTransaction();

	bool Process();
	string transactionInfo();
	

private:
	Customer* customer;
	string movie;
};

