#pragma once
class Transaction
{
public:
	Transaction();
	~Transaction();
	virtual bool Process() = 0;
};

