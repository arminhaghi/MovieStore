#pragma once
#include "Transaction.h"
#include "Movie.h"
#include "BSTree.h"
#include <vector>
#include <iostream>
using namespace std;

class InventoryTransaction : public Transaction
{
public:
	InventoryTransaction(BSTree<Movie> &argMovies);
	~InventoryTransaction();
	bool Process();
	string transactionInfo();
private:
	vector<Movie*> movies;
};

