#include "stdafx.h"
#include "FileReader.h"


FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

void FileReader::ReadData4Movies(const string &argFileName, vector<Movie*> &argMovies)
{
	ifstream file(argFileName);
	string stringForMakeMovie;
	while (!file.eof())
	{
		getline(file, stringForMakeMovie);
		if (stringForMakeMovie != "")
			argMovies.push_back(MovieFactory().makeMovie(split(stringForMakeMovie, ',')));
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

void FileReader::ReadData4Commands(const string &argFileName, HashTable<Customer> &argCustomers)
{
	ifstream file(argFileName);
	string stringForMakeTransaction;
	while (!file.eof())
	{
		getline(file, stringForMakeTransaction);
		vector<string> commands = split(stringForMakeTransaction, ' ');
		if (stringForMakeTransaction != "")
		{
			if (commands[0] == "i" || commands[0] == "I")
			{
				
			}
			else if (commands[0] == "h" || commands[0] == "H" || commands[0] == "b" || commands[0] == "B" || commands[0] == "r" || commands[0] == "R")
			{
				Customer x(stoi(commands[1]), "");
				if (argCustomers.Find(x, stoi(commands[1])))
					x.addTransaction(TransactionFactory().makeTransaction(commands));
				else
					cout << "Could not find customer " << stoi(commands[1]) << endl;
			}
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
		}
		else
		{
			argument += stringToSplit[i];
		}
	}
	stringArr.push_back(argument);
	return stringArr;
}