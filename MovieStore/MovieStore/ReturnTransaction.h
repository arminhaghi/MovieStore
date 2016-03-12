#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class ReturnTransaction : public Transaction
{
public:
	ReturnTransaction();
	~ReturnTransaction();
	bool Process();

private:
	Customer* customer;
	Movie* movie;
};

