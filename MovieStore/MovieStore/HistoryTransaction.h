/*
A HistoryTransaction object holds a object that is used to display 
the history of Transactions a Customer has done

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "HashTable.h"

//-----------------------------------------------------------------------------
// HistoryTransaction: A transaction that displays the Transaction 
// history of a customer
//
// Implementation and assumptions:
//
// -- The customer who's history is being displayed exists

class HistoryTransaction : public Transaction
{
public:
	//creates an instance of the HistoryTransaction class
	HistoryTransaction(HashTable<Customer> &argCustomers, const int &customerID);
	~HistoryTransaction();

	// performs the transaction
	bool Process(BSTree<Movie> movies);

	//prints the action done by this object
	void printTransactionInfo(ostream &out);

private:
	// a copy of the collection of customers in MovieStore
	HashTable<Customer> customers;

	// the ID of the customer 
	int customerID;
};

