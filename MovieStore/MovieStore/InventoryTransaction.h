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
	string transactionInfo();
private:
	BSTree<Movie> movies;
};

