#include "stdafx.h"
#include "FileReader.h"

//-----------------------------------------------------------------------------
// creates an instance of the FileReader class
FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

//-----------------------------------------------------------------------------
// reads text file containing data for Movies
void FileReader::ReadData4Movies(const string &argFileName, BSTree<Movie> &argMovies)
{
	ifstream file(argFileName.c_str());
	string stringForMakeMovie;
	while (getline(file, stringForMakeMovie))
	{
		if (stringForMakeMovie != "")
		{
			vector<string> movieInfo = split(stringForMakeMovie, ',');
			if (atoi(movieInfo[1].c_str()) < 1)
			{
				cout << "Can't accept negative amount for stock!" << endl;
				continue;
			}
			if (movieInfo[0] == "F" || movieInfo[0] == "C" || movieInfo[0] == "D")
			{
				Movie* pMovie = MovieFactory().makeMovie(movieInfo);
				Movie* exMovie;
				
				// If the movies exists, just increase stock
				if (argMovies.Retrieve(*pMovie, exMovie)) 
				{
					// Increase stock
					exMovie->increaseStock(atoi(movieInfo[1].c_str()));
					delete pMovie;
					pMovie = exMovie = NULL;
				}
				else
				{
					argMovies.Insert(pMovie);
				}
			}
			else
			{
				cout << endl << movieInfo[0] << " is not a valid movie genre!" << endl;
			}
		}
	}
}

//-----------------------------------------------------------------------------
// reads text file containing data for Customers
void FileReader::ReadData4Customers(const string &argFileName, HashTable<Customer> &argCustomers)
{
	ifstream file(argFileName.c_str());
	int ID;
	string lastName;
	string firstName;
	while (!file.eof())
	{
		if (file >> ID >> lastName >> firstName)
		{
			argCustomers.Insert(new Customer(ID, firstName + " " + lastName), ID);
		}
	}
}

//-----------------------------------------------------------------------------
// reads text file containing data for Commands
void FileReader::ReadData4Commands(const string &argFileName, HashTable<Customer> &argCustomers, BSTree<Movie> &movies, vector<Transaction*> transactions)
{
	ifstream file(argFileName.c_str());
	string stringForMakeTransaction;
	Transaction *trans;
	while (getline(file, stringForMakeTransaction))
	{
		vector<string> commands = split(stringForMakeTransaction, ' ');
		if (stringForMakeTransaction != "")
		{
			if (commands[0] == "I")
			{
				trans = TransactionFactory().makeTransaction(commands, argCustomers, movies);
				trans->Process(movies);
				delete trans;
			}
			else if (commands[0] == "H")
			{
				trans = TransactionFactory().makeTransaction(commands, argCustomers, movies);
				trans->Process(movies);
				delete trans;
			}
			else if (commands[0] == "B" || commands[0] == "R")
			{
				Customer *customerToRetrieve = new Customer();
				customerToRetrieve->setCustomerId(atoi(commands[1].c_str()));
				if (argCustomers.Find(customerToRetrieve, atoi(commands[1].c_str())))
				{
					trans = TransactionFactory().makeTransaction(commands, argCustomers, movies);
					if (trans->Process(movies))
					{
						customerToRetrieve->addTransaction(trans);
					}
				}
				else
				{
					cout << endl << "Could not find customer " << atoi(commands[1].c_str()) << endl;
				}
			}
			else
				cout << endl << commands[0] << " is not a valid transaction!" << endl;
		}
	}
}

//-----------------------------------------------------------------------------
// used to separate the lines of text into useful information
vector<string> FileReader::split(string stringToSplit, char separator)
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