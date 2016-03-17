/*
A TransactionFactory object is a class that is used to create Transaction objects

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include "Transaction.h"
#include "BorrowTransaction.h"
#include "HistoryTransaction.h"
#include "InventoryTransaction.h"
#include "ReturnTransaction.h"
#include "BSTree.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// TransactionFactory: a class that creates Transaction objects
//
// Implementation and assumptions:
//
// -- can not be instantiated

static class TransactionFactory
{
public:
	//used to create Transaction objects
	static Transaction* makeTransaction(const vector<string> transCreationInfo, HashTable<Customer> &argCustomers, BSTree<Movie> &argMovies);
private:
	//used to combine text data into useful information
	static string combineMovieData(vector<string> movieInfo);
};

