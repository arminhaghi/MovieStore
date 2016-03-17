#include "stdafx.h"
#include "MovieFactory.h"

//-----------------------------------------------------------------------------
// creates Movie objects
Movie * MovieFactory::makeMovie(const vector<string> movieCreationInfo)
{
	if (movieCreationInfo[0] == "F")
	{
		return new ComedyMovie(movieCreationInfo[2], movieCreationInfo[3], 'D', stoi(movieCreationInfo[4]), stoi(movieCreationInfo[1]));
	}
	else if (movieCreationInfo[0] == "C")
	{
		vector<string> actorYearInfo = splitActorAndDate(movieCreationInfo[4]);
		return new ClassicMovie(movieCreationInfo[2], movieCreationInfo[3], actorYearInfo[0], 'D', stoi(actorYearInfo[2]), stoi(actorYearInfo[1]), stoi(movieCreationInfo[1]));
	}
	else if (movieCreationInfo[0] == "D")
	{
		return new DramaMovie(movieCreationInfo[2], movieCreationInfo[3], 'D', stoi(movieCreationInfo[4]), stoi(movieCreationInfo[1]));
	}
}

//-----------------------------------------------------------------------------
// used to split lines of text from a file into useful information
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

//-----------------------------------------------------------------------------
// used to split the data that combines the actor name and release date
vector<string> MovieFactory::splitActorAndDate(string stringToSplit)
{
	vector<string> actorYearInfo = split(stringToSplit, ' ');
	string actorName = "";
	for (int i = 0; i < actorYearInfo.size() - 2; i++)
	{
		actorName += actorYearInfo[i];
		if (i != actorYearInfo.size() - 3)
		{
			actorName += " ";
		}
	}

	vector<string> returnArr = { actorName, actorYearInfo[actorYearInfo.size() - 2], actorYearInfo[actorYearInfo.size() - 1] };
	return returnArr;
}