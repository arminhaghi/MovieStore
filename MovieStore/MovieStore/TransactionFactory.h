#pragma once
#include "Transaction.h"
#include "BorrowTransaction.h"
#include "HistoryTransaction.h"
#include "InventoryTransaction.h"
#include "ReturnTransaction.h"
#include "BSTree.h"
#include <vector>
#include <iostream>
using namespace std;

static class TransactionFactory
{
public:
	static Transaction* makeTransaction(const vector<string> transCreationInfo, HashTable<Customer> &argCustomers, BSTree<Movie> &argMovies);
private:
	static string combineMovieData(vector<string> movieInfo);
};

