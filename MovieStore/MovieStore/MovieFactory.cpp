#include "stdafx.h"
#include "MovieFactory.h"

Movie * MovieFactory::makeMovie(string movieInfo)
{
	vector<string> movieCreationInfo = split(movieInfo, ',');

	if (movieCreationInfo[0] == "f" || movieCreationInfo[0] == "F")
		return new ComedyMovie(Person(movieCreationInfo[2]), movieCreationInfo[3], 'D', stoi(movieCreationInfo[4]), stoi(movieCreationInfo[1]));
	else if (movieCreationInfo[0] == "c" || movieCreationInfo[0] == "C")
	{
		vector<string> actorYearInfo = splitActorAndDate(movieCreationInfo[4]);
		return new ClassicMovie(Person(movieCreationInfo[2]), movieCreationInfo[3], Person(actorYearInfo[0]), 'D', stoi(actorYearInfo[2]), stoi(actorYearInfo[1]), stoi(movieCreationInfo[1]));
	}
	else if (movieCreationInfo[0] == "d" || movieCreationInfo[0] == "D")
		return new DramaMovie(Person(movieCreationInfo[2]), movieCreationInfo[3], 'D', stoi(movieCreationInfo[4]), stoi(movieCreationInfo[1]));
	else
		cout << movieCreationInfo[0] << " is not a movie code!" << endl;
}

vector<string> MovieFactory::split(string stringToSplit, char separator)
{
	string argument = "";
	vector<string> stringArr;
	for (int i = 0; i < stringToSplit.length(); i++)
	{
		if (stringToSplit[i] == separator)
		{
			stringArr.push_back(argument);
			argument = "";
			if(separator == ',')
				i++;
		}
		else
		{
			argument += stringToSplit[i];
		}
	}
	stringArr.push_back(argument);
	return stringArr;
}

vector<string> MovieFactory::splitActorAndDate(string stringToSplit)
{
	vector<string> actorYearInfo = split(stringToSplit, ' ');
	string actorName = "";
	for (int i = 0; i < actorYearInfo.size() - 2; i++)
	{
		actorName += actorYearInfo[i] + " ";
	}

	vector<string> returnArr = { actorName, actorYearInfo[actorYearInfo.size() - 2], actorYearInfo[actorYearInfo.size() - 1] };
	return returnArr;
}