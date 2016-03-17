#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
using namespace std;

class InventoryTransaction : public Transaction
{
public:
	InventoryTransaction(BSTree<Movie> &argMovies);
	~InventoryTransaction();

	bool Process(BSTree<Movie> movies);
	void printTransactionInfo(ostream &out);

private:
	BSTree<Movie> movies;
};

