#include "stdafx.h"
#include "ReturnTransaction.h"


ReturnTransaction::ReturnTransaction()
{
}

ReturnTransaction::ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string movieData)
{
}

ReturnTransaction::~ReturnTransaction()
{
}

bool ReturnTransaction::Process()
{
	return false;
}

string ReturnTransaction::transactionInfo() const
{
	return "Returned " + movie->getTitle();
}
