#pragma once
#include <iostream>
#include <fstream>
#include "MovieFactory.h"
#include "TransactionFactory.h"
#include <iostream>
using namespace std;

class FileReader
{
public:
	FileReader();
	~FileReader();

	void ReadData4Movies(const string &argFileName, vector<Movie*> &argMovies);
	void ReadData4Customers(const string &argFileName, HashTable<Customer> &argCustomers);
	void ReadData4Commands(const string &argFileName, HashTable<Customer> &argCustomers, vector<Movie*> movies, vector<Transaction*> transactions);

private:
	vector<string> split(string stringToSplit, char separator);
};
