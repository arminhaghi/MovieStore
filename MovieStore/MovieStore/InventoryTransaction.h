#pragma once
#include "Transaction.h"
#include "Movie.h"
#include <vector>
#include <iostream>
using namespace std;

class InventoryTransaction : public Transaction
{
public:
	InventoryTransaction(vector<Movie*> &argMovies);
	~InventoryTransaction();
	bool Process();
	string transactionInfo() const;
private:
	vector<Movie*> movies;
};
