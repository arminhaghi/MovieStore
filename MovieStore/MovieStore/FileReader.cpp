#include "stdafx.h"
#include "FileReader.h"


FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

void FileReader::ReadData4Movies(const string &argFileName)
{
	ifstream file(argFileName);
	string stringForMakeMovie;
	while (!file.eof())
	{
		getline(file, stringForMakeMovie);
		if(stringForMakeMovie != "")
			MovieFactory().makeMovie(stringForMakeMovie);
	}
}

void FileReader::ReadData4Commands(const string &argFileName)
{
	ifstream file(argFileName);
	string stringForMakeTransaction;
	while (!file.eof())
	{
		getline(file, stringForMakeTransaction);
		if (stringForMakeTransaction != "")
			TransactionFactory().makeTransaction(stringForMakeTransaction);
	}
}