#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class BorrowTransaction : public Transaction
{
public:
	BorrowTransaction();
	~BorrowTransaction();
	bool Process();

private:
	Customer* customer;
	Movie* movie;
};

