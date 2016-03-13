#pragma once
#include "Transaction.h"
#include "BorrowTransaction.h"
#include "HistoryTransaction.h"
#include "InventoryTransaction.h"
#include "ReturnTransaction.h"
#include <vector>

static class TransactionFactory
{
public:
	static Transaction* makeTransaction(string movieInfo);
private:
	static vector<string> split(string stringToSplit, char separator);
};

