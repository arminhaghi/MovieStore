#pragma once
#include <iostream>
using namespace std;
class Transaction
{
public:
	Transaction();
	~Transaction();
	virtual bool Process() = 0;
	virtual string transactionInfo();
};

