// MovieStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileReader.h"
#include <iostream>
#include "vld.h"

int main()
{
	HashTable<Customer> customers;
	BSTree<Movie> movies;

	FileReader fileReader;
	fileReader.ReadData4Movies("data4movies.txt", movies);
	fileReader.ReadData4Customers("data4customers.txt", customers);
	fileReader.ReadData4Commands("data4commands.txt", customers, movies);

	return 0;
}
