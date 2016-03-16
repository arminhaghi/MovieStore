#include "stdafx.h"
#include "TransactionFactory.h"

Transaction* TransactionFactory::makeTransaction(const vector<string> transCreationInfo, HashTable<Customer> &argCustomers, BSTree<Movie> &argMovies)
{
	if (transCreationInfo[0] == "I")
	{
		return new InventoryTransaction(argMovies);
	}
	else if (transCreationInfo[0] == "H")
	{
		return new HistoryTransaction(argCustomers, stoi(transCreationInfo[1]));
	}
	else if (transCreationInfo[0] == "B")
	{
		
		return new BorrowTransaction(stoi(transCreationInfo[1]), transCreationInfo[2].c_str()[0], transCreationInfo[3].c_str()[0], combineMovieData(transCreationInfo));
	}
	else if (transCreationInfo[0] == "R")
	{
		return new ReturnTransaction(stoi(transCreationInfo[1]), transCreationInfo[2].c_str()[0], transCreationInfo[3].c_str()[0], combineMovieData(transCreationInfo));
	}
	else
	{
		// We presumably would never come to here, since this was checked once before in fileReader
		// To Do: might wanna delete this
		cout << transCreationInfo[0] << " is not an action code!" << endl;
		return NULL;
	}
}

string TransactionFactory::combineMovieData(vector<string> movieInfo)
{
	string movieData = "";
	for (int i = 4; i < movieInfo.size(); i++)
	{
		movieData += movieInfo[i] + " ";
	}

	return movieData;
}