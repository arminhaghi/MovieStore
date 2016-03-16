#include "stdafx.h"
#include "ReturnTransaction.h"


ReturnTransaction::ReturnTransaction()
{
}

ReturnTransaction::ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieName)
{
	movie = movieName;
}

ReturnTransaction::~ReturnTransaction()
{
}

bool ReturnTransaction::Process()
{
	return false;
}

string ReturnTransaction::transactionInfo()
{
	return "Returned " + movie;
}
