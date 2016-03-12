#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"

class HistoryTransaction : public Transaction
{
public:
	HistoryTransaction();
	~HistoryTransaction();
	bool Process();

private:
	Customer* customer;

};

