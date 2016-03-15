#include "stdafx.h"
#include "TransactionFactory.h"

Transaction* TransactionFactory::makeTransaction(const vector<string> transCreationInfo)
{
	if (transCreationInfo[0] == "I" || transCreationInfo[0] == "i")
		return new InventoryTransaction();
	else if(transCreationInfo[0] == "H" || transCreationInfo[0] == "h")
		return new HistoryTransaction(stoi(transCreationInfo[1]));
	else if (transCreationInfo[0] == "B" || transCreationInfo[0] == "b")
		return new BorrowTransaction(stoi(transCreationInfo[1]), transCreationInfo[2].c_str()[0], transCreationInfo[3].c_str()[0], combineMovieData(transCreationInfo));
	else if (transCreationInfo[0] == "R" || transCreationInfo[0] == "r")
		return new ReturnTransaction(stoi(transCreationInfo[1]), transCreationInfo[2].c_str()[0], transCreationInfo[3].c_str()[0], combineMovieData(transCreationInfo));
	else
		cout << transCreationInfo[0] << " is not an action code!" << endl;
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