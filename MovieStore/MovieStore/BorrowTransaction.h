#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class BorrowTransaction : public Transaction
{
public:
	BorrowTransaction();
	BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string movieData);
	~BorrowTransaction();

	string transactionInfo() const;
	bool Process();

private:
	Customer* customer;
	Movie* movie;
};

