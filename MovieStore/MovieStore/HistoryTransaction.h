#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class HistoryTransaction : public Transaction
{
public:
	HistoryTransaction();
	HistoryTransaction(const int &customerID);
	~HistoryTransaction();
	bool Process();

private:
	Customer* customer;

};

