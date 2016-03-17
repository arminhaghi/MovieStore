#pragma once
#include <iostream>
#include "BSTree.h"
#include "Movie.h"
using namespace std;
class Transaction
{
	friend ostream& operator<<(ostream& out, Transaction &trans);
public:
	Transaction();
	~Transaction();

	virtual bool Process(BSTree<Movie> movies) = 0;
	virtual void printTransactionInfo(ostream &out) = 0;

};

