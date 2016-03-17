#include "stdafx.h"
#include "ReturnTransaction.h"
#include "BSTree.h"

//-----------------------------------------------------------------------------
// creates an instance of the ReturnTransaction class
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

//-----------------------------------------------------------------------------
// performs the transaction
bool ReturnTransaction::Process(BSTree<Movie> movies)
{
	return false;
}

//-----------------------------------------------------------------------------
//prints the action done by this object
void ReturnTransaction::printTransactionInfo(ostream &out)
{
	out << "Returned " + movie;
}