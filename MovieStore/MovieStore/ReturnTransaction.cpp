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

void ReturnTransaction::printTransactionInfo(ostream &out)
{
	out << "Returned " + movie;
}