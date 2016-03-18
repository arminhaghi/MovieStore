// MovieStore.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "Movie.h"
#include <iostream>
#include "FileReader.h"
#include "BSTree.h"

int main()
{
	//HashTable<Customer> customers;
	//BSTree<Movie> movies;
	//vector<Transaction*> transactions;

	//FileReader fileReader;
	//fileReader.ReadData4Movies("data4movies.txt", movies);
	//fileReader.ReadData4Customers("data4customers.txt", customers);
	//fileReader.ReadData4Commands("data4commands.txt", customers, movies, transactions);

	int i = 1;
	string s = "1";

	Customer* c1 = new Customer(i, s);

	//Customer* c2 = new Customer(2, "2");
	//Customer* c3 = new Customer(1, "3");

	//customers.Insert(c1, 1);
	//customers.Insert(c2, 1);
	//customers.Insert(c3, 1);

	//movies.Empty();

	return 0;
}
