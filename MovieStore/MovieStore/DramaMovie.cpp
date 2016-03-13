#include "stdafx.h"
#include "DramaMovie.h"


DramaMovie::DramaMovie()
{
}

DramaMovie::DramaMovie(const Person & argDirector, const string & argTitle, const char & argType, const int & argYear, const int &argAmount)
{
	setDirector(argDirector);
	setTile(argTitle);
	type = argType;
	setReleaseYear(argYear);
}

DramaMovie::~DramaMovie()
{
}

char DramaMovie::getIdentifier() const
{
	return identifier;
}
