/*
A FileReader object holds an object used to read files associated
with MovieStore

Author: Kyle Burney
*/

#pragma once
#include <iostream>
#include <fstream>
#include "MovieFactory.h"
#include "TransactionFactory.h"
#include "HashTable.h"
#include "BSTree.h"
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// FileReader: Used to read files associated with MovieStore
//
// Implementation and assumptions:
//
// -- A file exists for Movie data
// -- A file exists for Customer data
// -- A file exists for Commands data

class FileReader
{
public:
	// creates an instance of the FileReader class
	FileReader();
	~FileReader();

	// reads text file containing data for Movies
	void ReadData4Movies(const string &argFileName, BSTree<Movie> &argMovies);

	// reads text file containing data for Customers
	void ReadData4Customers(const string &argFileName, 
				HashTable<Customer> &argCustomers);

	// reads text file containing data for Commands
	void ReadData4Commands(const string &argFileName, HashTable<Customer> 
								&argCustomers, BSTree<Movie> movies, 
								vector<Transaction*> transactions);

private:
	// used to separate the lines of text into useful information
	vector<string> split(string stringToSplit, char separator);
};

