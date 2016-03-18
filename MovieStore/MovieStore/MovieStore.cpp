// MovieStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Movie.h"
#include <iostream>
#include "FileReader.h"
#include "BSTree.h"

int main()
{
	HashTable<Customer> customers;
	BSTree<Movie> movies;
	//Customer x(2000, "Ducky Donald");
	vector<Transaction*> transactions;

	FileReader fileReader;
	fileReader.ReadData4Movies("data4movies.txt", movies);
	fileReader.ReadData4Customers("data4customers.txt", customers);
	fileReader.ReadData4Commands("data4commands.txt", customers, movies, transactions);


	for (int i = 0; i < transactions.size(); i++)
	{
		delete transactions.at(i);
	}

	movies.Empty();

	return 0;
}
