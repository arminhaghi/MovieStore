#include "stdafx.h"
#include "ComedyMovie.h"


ComedyMovie::ComedyMovie()
{
}

ComedyMovie::ComedyMovie(const Person & argDirector, const string & argTitle, const char & argType, const int & argYear)
{
	setDirector(argDirector);
	setTile(argTitle);
	type = argType;
	setReleaseYear(argYear);
}


ComedyMovie::~ComedyMovie()
{
}

char ComedyMovie::getIdentifier() const
{
	return identifier;
}
