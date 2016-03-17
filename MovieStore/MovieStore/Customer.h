/*
A Customer object holds a customer of MovieStore

Author: Armin Haghi, Kyle Burney
*/

#pragma once
#include <string>
#include "Transaction.h"
#include <vector>
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
// Customer: A customer of MovieStore
//
// Implementation and assumptions:
//
// -- Each customer has a name and an ID
// -- Customers can call Transactions and hold them in their history

class Customer
{
public:
	// creates an instance of the Customer class
	Customer();
	Customer(const int &argCustomerId,  const string &argName);
	~Customer();

	// Operator Functions
	bool operator<(const Customer &customer) const;
	bool operator>(const Customer &customer) const;
	bool operator==(const Customer &customer) const;

	// gets the ID of the customer
	int getCustomerId() const;

	// sets the ID of the customer
	void setCustomerId(int id);

	// gets the name of the customer
	string getName() const;

	// adds a transaction to the Customer's collection of Transactions
	void addTransaction(Transaction *trans);

	// displays the history of Transactions done by the Customer
	void displayHistory() const;

private:
	// the ID of the Customer
	int customerId;

	// the name of the Customer
	string name;

	// the collection of Transactions done by the Customer
	vector<Transaction*> transactions;

	// the history of transactions that the Customer has done
	vector<string> history;
};