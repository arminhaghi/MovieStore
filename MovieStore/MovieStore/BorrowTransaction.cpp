#include "stdafx.h"
#include "BorrowTransaction.h"


BorrowTransaction::BorrowTransaction()
{
}

BorrowTransaction::BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string movieData)
{
}

BorrowTransaction::~BorrowTransaction()
{
}

string BorrowTransaction::transactionInfo() const
{
	return "Borrowed " + movie->getTitle();
}

bool BorrowTransaction::Process()
{

	return false;
}
