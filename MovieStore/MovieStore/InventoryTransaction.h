/*
An InventoryTransaction object holds a object that is used to display
the inventory of Movies in MovieStore

Authors: Kyle Burney, Armin Haghi
*/

#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// InventoryTransaction: A transaction that displays the Transaction 
// inventory of Movies in MovieStore
//
// Implementation and assumptions:
//
// -- anybody can call this transaction, no customerID necesary

class InventoryTransaction : public Transaction
{
public:
	// creates an instance of the InventoryTransaction class
	InventoryTransaction();
	~InventoryTransaction();
	
	char getIdentifier() const;
	// performs the transaction
	bool Process(BSTree<Movie> &movies);

	//prints the action done by this object
	void printTransactionInfo(ostream &out);

private:
	char identifier;
};

