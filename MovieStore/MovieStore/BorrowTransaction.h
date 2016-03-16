#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class BorrowTransaction : public Transaction
{
	friend ostream& operator<<(ostream& os, const BorrowTransaction &transaction);
public:
	BorrowTransaction();
	BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieData);
	~BorrowTransaction();

	string getMovie() const;
	bool Process();

private:
	Customer* customer;
	Movie* movie;
};

