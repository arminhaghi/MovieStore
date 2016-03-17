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

class ReturnTransaction : public Transaction
{
public:
	ReturnTransaction();
	ReturnTransaction(const int &customerID, const char &mediaType, const char &genre, const string &argMovieInfo, const BSTree<Movie> &argMovies, const HashTable<Customer> &argCustomers);
	~ReturnTransaction();

	char getIdentifier() const;
	Movie * getMovie() const;
	bool Process(BSTree<Movie> movies);
	void printTransactionInfo(ostream &out);

private:
	char identifier = 'R';
	bool valid;
	Customer* customer;
	Movie* movie;
	string movieInfo;

	vector<string> split(string stringToSplit, char separator);
};

