#include "stdafx.h"
#include "TransactionFactory.h"

Transaction * TransactionFactory::makeTransaction(string movieInfo)
{
	vector<string> transCreationInfo = split(movieInfo, ',');
	
	return nullptr;
}

vector<string> TransactionFactory::split(string stringToSplit, char separator)
{
	string argument = "";
	vector<string> stringArr;

	for (int i = 0; i < stringToSplit.length(); i++)
	{
		if (stringToSplit[i] == separator)
		{
			stringArr.push_back(argument);
			argument = "";
			i++;
		}
		else
		{
			argument += stringToSplit[i];
		}
	}
	return stringArr;
}
