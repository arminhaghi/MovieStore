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

void BorrowTransaction::printTransactionInfo(ostream& out)
{
	out << "Borrowed " + movie;
}

bool BorrowTransaction::Process(BSTree<Movie> movies)
{

	return false;
}
