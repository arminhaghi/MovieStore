//#include "stdafx.h"
#include "Transaction.h"


Transaction::Transaction()
{
}


Transaction::~Transaction()
{
}

Movie * Transaction::getMovie() const
{
	return NULL;
	//return nullptr;
}

ostream& operator<<(ostream& out, Transaction &trans)
{
	trans.printTransactionInfo(out);
	return out;
}