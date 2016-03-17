#include "stdafx.h"
#include "FileReader.h"


FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

void FileReader::ReadData4Movies(const string &argFileName, BSTree<Movie> &argMovies)
{
	ifstream file(argFileName);
	string stringForMakeMovie;
	while (!file.eof())
	{
		getline(file, stringForMakeMovie);
		if (stringForMakeMovie != "")
		{
			vector<string> movieInfo = split(stringForMakeMovie, ',');
			if (movieInfo[0] == "F" || movieInfo[0] == "C" || movieInfo[0] == "D")
			{
				Movie* pMovie = MovieFactory().makeMovie(movieInfo);
				Movie* exMovie;
				
				// If the movies exists, just increase stock
				if (argMovies.Retrieve(*pMovie, exMovie)) 
				{
					// Increase stock
					exMovie->increaseStock(stoi(movieInfo[1]));
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

void FileReader::ReadData4Customers(const string &argFileName, HashTable<Customer> &argCustomers)
{
	ifstream file(argFileName);
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

void FileReader::ReadData4Commands(const string &argFileName, HashTable<Customer> &argCustomers, BSTree<Movie> movies, vector<Transaction*> transactions)
{
	ifstream file(argFileName);
	string stringForMakeTransaction;
	Transaction *trans;
	while (!file.eof())
	{
		getline(file, stringForMakeTransaction);
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
				customerToRetrieve->setCustomerId(stoi(commands[1]));
				if (argCustomers.Find(customerToRetrieve, stoi(commands[1])))
				{
					trans = TransactionFactory().makeTransaction(commands, argCustomers, movies);
					if (trans->Process(movies))
					{
						customerToRetrieve->addTransaction(trans);
					}
				}
				else
				{
					cout << endl << "Could not find customer " << stoi(commands[1]) << endl;
				}
			}
			else
				cout << endl << commands[0] << " is not a valid transaction!" << endl;
		}
	}
}

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