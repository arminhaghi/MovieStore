#include "stdafx.h"
#include "Transaction.h"


Transaction::Transaction()
{
}


Transaction::~Transaction()
{
}

ostream& operator<<(ostream& out, Transaction &trans)
{
	trans.printTransactionInfo(out);
	return out;
}