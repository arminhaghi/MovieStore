#include "stdafx.h"
#include "ReturnTransaction.h"
#include "BSTree.h"

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

bool ReturnTransaction::Process(BSTree<Movie> movies)
{
	return false;
}

string ReturnTransaction::transactionInfo()
{
	return "Returned " + movie;
}
