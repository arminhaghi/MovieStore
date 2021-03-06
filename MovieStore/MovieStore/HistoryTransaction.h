/*
A HistoryTransaction object holds a object that is used to display 
the history of Transactions a Customer has done

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "HashTable.h"
#include <string>
using namespace std;

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
	HistoryTransaction();
	HistoryTransaction(HashTable<Customer> &argCustomers, 
								const int &customerID);
	~HistoryTransaction();

	char getIdentifier() const;
	// performs the transaction
	bool Process(BSTree<Movie> &movies);

	//prints the action done by this object
	void printTransactionInfo(ostream &out);

private:
	char identifier;

	// a copy of the collection of customers in MovieStore
	HashTable<Customer> customers;

	// the ID of the customer 
	int customerID;
};

