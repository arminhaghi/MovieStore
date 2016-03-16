// MovieStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include <iostream>
#include "MovieFactory.h"
#include "FileReader.h"

int main()
{
	HashTable<Customer> customers;
	vector<Movie*> movies;
	vector<Transaction*> transactions;

	FileReader fileReader;
	fileReader.ReadData4Movies("data4movies.txt", movies);
	fileReader.ReadData4Customers("data4customers.txt", customers);
	fileReader.ReadData4Commands("data4commands.txt", customers, movies, transactions);


	return 0;
}
