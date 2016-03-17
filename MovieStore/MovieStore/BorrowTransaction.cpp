#include "stdafx.h"
#include "BorrowTransaction.h"

BorrowTransaction::BorrowTransaction()
{
}

BorrowTransaction::BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &argMovieInfo, const BSTree<Movie> &argMovies, const HashTable<Customer> &argCustomers)
{
	valid = true;
	movieInfo = argMovieInfo;
	customer = new Customer();
	customer->setCustomerId(customerID);

	if (!argCustomers.Find(customer, customerID))
	{
		valid = false;
		cout << "Could not find customer " << customerID << endl;
		return;
	}

	if (genre == 'F')
	{
		vector<string> parts = split(argMovieInfo, ',');
		ComedyMovie m("director", parts[0], mediaType, stoi(parts[1]), 0);
		argMovies.Retrieve(m, movie);
	}
	else if (genre == 'D')
	{
		vector<string> parts = split(argMovieInfo, ',');
		DramaMovie m(parts[0], parts[1], mediaType, 2000, 0); // 2000 is a random number. Can be anything. To Do: Fix
		argMovies.Retrieve(m, movie);
	}
	else if (genre == 'C')
	{
		vector<string> parts = split(argMovieInfo, ' ');
		ClassicMovie m("director", "title", parts[2] + ' ' + parts[3], mediaType, stoi(parts[1]), stoi(parts[0]), 0);
		argMovies.Retrieve(m, movie);
		if (movie->getStock() == 0)
		{
			vector<Movie*> movies;
			argMovies.RetrieveAll(m, movies);

			for (int i = 0; i < movies.size(); i++)
			{
				if (movies.at(i)->getStock() > 0)
				{
					movie = movies.at(i);
				}
			}
		}
	}
	else
	{
		valid = false;
		cout << movieInfo[0] << " is not a valid movie genre!" << endl;
	}
}

BorrowTransaction::~BorrowTransaction()
{
}

string BorrowTransaction::transactionInfo()
{
	return "Borrowed " + movieInfo;
}

bool BorrowTransaction::Process()
{
	if (valid)
	{
		movie->updateStock(-1);
		return true;
	}
	return false;
}

vector<string> BorrowTransaction::split(string stringToSplit, char separator)
{
	string argument = "";
	vector<string> stringArr;

	for (int i = 0; i < stringToSplit.length(); i++)
	{
		if (stringToSplit[i] == separator)
		{
			stringArr.push_back(argument);
			argument = "";
		}
		else
		{
			argument += stringToSplit[i];
		}
	}
	stringArr.push_back(argument);
	return stringArr;
}