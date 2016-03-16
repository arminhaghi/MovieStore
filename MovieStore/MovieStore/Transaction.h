#pragma once
#include <iostream>
#include "BSTree.h"
#include "Movie.h"
using namespace std;
class Transaction
{
public:
	Transaction();
	~Transaction();
	virtual bool Process(BSTree<Movie> movies) = 0;
	virtual string transactionInfo() = 0;
};

