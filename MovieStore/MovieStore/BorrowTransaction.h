#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class BorrowTransaction : public Transaction
{
public:
	BorrowTransaction();
	BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieName);
	~BorrowTransaction();

	string transactionInfo();
	bool Process();

private:
	Customer* customer;
	string movie;
};

