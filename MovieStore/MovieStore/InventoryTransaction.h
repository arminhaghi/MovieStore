/*
An InventoryTransaction object holds a object that is used to display
the inventory of Movies in MovieStore

Authors: Kyle Burney, Armin Haghi
*/

#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
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
	InventoryTransaction(BSTree<Movie> &argMovies);
	~InventoryTransaction();

	// performs the transaction
	bool Process(BSTree<Movie> movies);

	//prints the action done by this object
	void printTransactionInfo(ostream &out);

private:
	// a copy of the Movie collection in MovieStore
	BSTree<Movie> movies;
};

