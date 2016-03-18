#include "stdafx.h"
#include "BorrowTransaction.h"

//-----------------------------------------------------------------------------
// creates an instance of the BorrowTransaction class
BorrowTransaction::BorrowTransaction()
{
	identifier = 'B';
	movie = NULL;
}

BorrowTransaction::BorrowTransaction(const int &customerID, const char &mediaType, const char &genre, const string &argMovieInfo, const BSTree<Movie> &argMovies, const HashTable<Customer> &argCustomers)
{
	movie = NULL;
	identifier = 'B';
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
		ComedyMovie m("director", parts[0], mediaType, atoi(parts[1].c_str()), 0);
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
		
		ClassicMovie m("director", "title", parts[2] + ' ' + parts[3], mediaType, atoi(parts[1].c_str()), atoi(parts[0].c_str()), 0);
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

	if (movie == NULL)
	{
		valid = false;
		cout << argMovieInfo << " is not a valid movie!" << endl;
	}
}

BorrowTransaction::~BorrowTransaction()
{
	customer = NULL;
	movie = NULL;
}

char BorrowTransaction::getIdentifier() const
{
	return identifier;
}

Movie* BorrowTransaction::getMovie() const
{
	return movie;
}

//-----------------------------------------------------------------------------
//prints the action done by this object
void BorrowTransaction::printTransactionInfo(ostream& out)
{
	out << "Borrowed " + movieInfo;
}

//-----------------------------------------------------------------------------
// performs the Borrowing of a Movie
bool BorrowTransaction::Process(BSTree<Movie> &movies)
{
	if (valid)
	{
		if (movie->getStock() > 0)
		{
			movie->updateStock(-1);
			return true;
		}
		else
		{
			cout << movieInfo << " is out of stock!" << endl;
			return false;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------
// used to separate information given from text file
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
			if (separator == ',')
			{
				i++;
			}
		}
		else
		{
			argument += stringToSplit[i];
		}
	}
	stringArr.push_back(argument);
	return stringArr;
}