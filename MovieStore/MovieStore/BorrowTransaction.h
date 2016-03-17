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

class BorrowTransaction : public Transaction
{
public:
	BorrowTransaction();
	BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &argMovieInfo, const BSTree<Movie> &argMovies, const HashTable<Customer> &argCustomers);
	~BorrowTransaction();

	string transactionInfo();
	bool Process();

private:
	bool valid;
	Customer* customer;
	Movie* movie;
	string movieInfo;

	vector<string> split(string stringToSplit, char separator);
};

