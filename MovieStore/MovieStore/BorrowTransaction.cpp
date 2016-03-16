#include "stdafx.h"
#include "BorrowTransaction.h"


BorrowTransaction::BorrowTransaction()
{
}

BorrowTransaction::BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieData)
{

}

BorrowTransaction::~BorrowTransaction()
{
}

string BorrowTransaction::getMovie() const
{
	return movie->getTitle();
}

bool BorrowTransaction::Process()
{

	return false;
}

ostream& operator<<(ostream& os, const BorrowTransaction &transaction)
{
	os << "B " << transaction.getMovie() << endl;
	return os;
}