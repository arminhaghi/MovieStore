#include "stdafx.h"
#include "ClassicMovie.h"


ClassicMovie::ClassicMovie()
{
}

ClassicMovie::ClassicMovie(const Person & argDirector, const string & argTitle, const Person & argActor, const char & argType, const int & argYear, const int & argMonth, const int &argAmount)
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

Person ClassicMovie::getActor()
{
	return actor;
}

void ClassicMovie::setActor(const Person & argActor)
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
