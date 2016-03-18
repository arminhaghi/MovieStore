/*
An Transaction object holds a generic transaction

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include <iostream>
#include "BSTree.h"
#include "Movie.h"
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// Transaction: A transaction that is done in MovieStore
//
// Implementation and assumptions:
//
// -- will be inherited by specific types of Transactions

class Transaction
{
	// displays the transaction that was performed
	friend ostream& operator<<(ostream& out, Transaction &trans);
public:
	// creates an instance of the Transaction class
	Transaction();
	virtual ~Transaction();

	virtual char getIdentifier() const = 0;
	virtual Movie* getMovie() const;
	// performs the transaction
	virtual bool Process(BSTree<Movie> &movies) = 0;

	//prints the action done by this object
	virtual void printTransactionInfo(ostream &out) = 0;

};

