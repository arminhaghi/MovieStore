/*
A BorrowTransaction object holds a object that is used to Borrow a Movie from 
from the MovieStore

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include "Transaction.h"
#include "Customer.h"
#include "BSTree.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include "HashTable.h"
#include <vector>

//-----------------------------------------------------------------------------
// BorrowTransaction: A transaction that Borrows Movies from MovieStore
//
// Implementation and assumptions:
//
// -- The customer performing this transaction exists
// -- The Movie being borrowed exists and is not out of stock

class BorrowTransaction : public Transaction
{
public:
	// creates an instance of the BorrowTransaction class
	BorrowTransaction();
	BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &argMovieInfo, const BSTree<Movie> &argMovies, const HashTable<Customer> &argCustomers);
	~BorrowTransaction();

	//prints the action done by this object
	void printTransactionInfo(ostream &out);

	// performs the Borrowing of a Movie
	bool Process(BSTree<Movie> movies);

private:
	// ensures the customer exists and the movie exists and can be borrowed
	bool valid;

	// pointer to the customer performing the transaction
	Customer* customer;

	// pointer to the movie being borrowed
	Movie* movie;

	// holds the information about the movie being borrowed
	string movieInfo;

	// used to separate information given from text file
	vector<string> split(string stringToSplit, char separator);
};

