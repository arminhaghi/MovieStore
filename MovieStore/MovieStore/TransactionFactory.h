#pragma once
#include "Transaction.h"
#include "BorrowTransaction.h"
#include "HistoryTransaction.h"
#include "InventoryTransaction.h"
#include "ReturnTransaction.h"
#include <vector>
#include <iostream>
using namespace std;

static class TransactionFactory
{
public:
	static Transaction* makeTransaction(const string &argMovieInfo);
private:
	static vector<string> split(string stringToSplit, char separator);
	static string combineMovieData(vector<string> movieInfo);
};

