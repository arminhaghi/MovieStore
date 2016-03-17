/*
An ReturnTransaction object holds a object that is used to Return
movies to the MovieStore

Authors: Kyle Burney, Armin Haghi
*/

#pragma once
#include "Transaction.h"
#include "Customer.h"

//-----------------------------------------------------------------------------
// ReturnTransaction: A transaction that returns Movies to MovieStore
//
// Implementation and assumptions:
//
// -- The customer performing this transaction exists
// -- The Movie being returned was actually borrowed 
// -- by the customer

class ReturnTransaction : public Transaction
{
public:
	// creates an instance of the ReturnTransaction class
	ReturnTransaction();
	ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string &movieName);
	~ReturnTransaction();

	// performs the transaction
	bool Process(BSTree<Movie> movies);

	//prints the action done by this object
	void printTransactionInfo(ostream &out);
	

private:
	// a pointer to the customer returning a movie
	Customer* customer;

	// the information used to look up the movie
	string movie;
};

