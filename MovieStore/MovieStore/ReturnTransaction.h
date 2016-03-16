#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class ReturnTransaction : public Transaction
{
public:
	ReturnTransaction();
	ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string movieData);
	~ReturnTransaction();

	bool Process();
	string transactionInfo() const;
	

private:
	Customer* customer;
	Movie* movie;
};

