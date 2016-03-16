#include "stdafx.h"
#include "BorrowTransaction.h"


BorrowTransaction::BorrowTransaction()
{
}

BorrowTransaction::BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieName)
{
	movie = movieName;
}

BorrowTransaction::~BorrowTransaction()
{
}

string BorrowTransaction::transactionInfo()
{
	return "Borrowed " + movie;
}

bool BorrowTransaction::Process(BSTree<Movie> movies)
{

	return false;
}
