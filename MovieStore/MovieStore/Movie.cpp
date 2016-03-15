#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
}

//Movie::Movie(const char & argIndentifier, const Person & argDirector, const string & argTitle, const char & argType, const int & argYear)
//{
//	identifier = argIndentifier;
//	setDirector(argDirector);
//	setTile(argTitle);
//	type = argType;
//	setReleaseYear(argYear);
//}


Movie::~Movie()
{
}

string Movie::getDirector() const
{
	return director;
}

string Movie::getTitle() const
{
	return title;
}

char Movie::getType() const
{
	return type;
}

int Movie::getReleaseYear() const
{
	return releaseYear;
}

void Movie::setDirector(const string & argPerson)
{
	director = argPerson;
}

void Movie::setTile(const string & argTitle)
{
	title = argTitle;
}

void Movie::setReleaseYear(const int & argYear)
{
	releaseYear = argYear;
}

string Movie::getActor()
{
	return "";
}

int Movie::getReleaseMonth()
{
	return -1;
}

void Movie::setReleaseMonth(int argMonth)
{
}
