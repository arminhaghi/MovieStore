#pragma once
#include "Transaction.h"
class InventoryTransaction : public Transaction
{
public:
	InventoryTransaction();
	~InventoryTransaction();
	bool Process();

};

