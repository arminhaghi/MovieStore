#include "stdafx.h"
#include "ClassicMovie.h"


ClassicMovie::ClassicMovie()
{
}

ClassicMovie::ClassicMovie(const string & argDirector, const string & argTitle, const string & argActor, const char & argType, const int & argYear, const int & argMonth, const int &argAmount)
{
	setDirector(argDirector);
	setActor(argActor);
	setTile(argTitle);
	type = argType;
	setReleaseYear(argYear);
	setReleaseMonth(argMonth);
}


ClassicMovie::~ClassicMovie()
{
}

string ClassicMovie::getActor()
{
	return actor;
}

void ClassicMovie::setActor(const string & argActor)
{
	actor = argActor;
}

int ClassicMovie::getReleaseMonth()
{
	return releaseMonth;
}

void ClassicMovie::setReleaseMonth(int argMonth)
{
	releaseMonth = argMonth;
}

char ClassicMovie::getIdentifier() const
{
	return identifier;
}
