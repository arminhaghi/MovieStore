//#include "stdafx.h"
#include "ClassicMovie.h"

//-----------------------------------------------------------------------------
// creates instance of a ClassicMovie
ClassicMovie::ClassicMovie()
{
	identifier = 'c';
}

ClassicMovie::ClassicMovie(const string & argDirector, const string & argTitle, const string & argActor, const char & argType, const int & argYear, const int & argMonth, const int &argAmount)
{
	identifier = 'c';
	setDirector(argDirector);
	setActor(argActor);
	setTile(argTitle);
	type = argType;
	setReleaseYear(argYear);
	setReleaseMonth(argMonth);
	stock = argAmount;
}


ClassicMovie::~ClassicMovie()
{
}

//-----------------------------------------------------------------------------
// returns the name of the star actor
string ClassicMovie::getActor() const
{
	return actor;
}

//-----------------------------------------------------------------------------
// sets the name of the star actor
void ClassicMovie::setActor(const string & argActor)
{
	actor = argActor;
}

//-----------------------------------------------------------------------------
// returns the month the movie was released
int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}

//-----------------------------------------------------------------------------
// sets the month the movie was released
void ClassicMovie::setReleaseMonth(int argMonth)
{
	releaseMonth = argMonth;
}

//-----------------------------------------------------------------------------
char ClassicMovie::getIdentifier() const
{
	return identifier;
}

//-----------------------------------------------------------------------------
// Operator Functions
bool ClassicMovie::operator==(const Movie & movie) const
{
	const ClassicMovie* pMovie = dynamic_cast<const ClassicMovie*>(&movie);
	if (pMovie != NULL)
	{
		if (pMovie->getActor() == "")
		{
			return isEqualNoActor(pMovie);
		}
		return isEqual(pMovie);
	}
	return false;
}

bool ClassicMovie::operator!=(const Movie & movie) const
{
	const ClassicMovie* pMovie = dynamic_cast<const ClassicMovie*>(&movie);
	if (pMovie != NULL)
	{
		return !isEqual(pMovie);
	}
	return false;
}

bool ClassicMovie::operator<=(const Movie & movie) const
{
	return (*this == movie) || (*this < movie);
}

bool ClassicMovie::operator<(const Movie & movie) const
{
	if (identifier != movie.getIdentifier())
	{
		return identifier > movie.getIdentifier();
	}
	const ClassicMovie* pMovie = dynamic_cast<const ClassicMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isLess(pMovie);
	}
	return false;
}

bool ClassicMovie::operator>(const Movie & movie) const
{
	if (identifier != movie.getIdentifier())
	{
		return identifier < movie.getIdentifier();
	}
	const ClassicMovie* pMovie = dynamic_cast<const ClassicMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isGreater(pMovie);
	}
	return false;
}

bool ClassicMovie::operator>=(const Movie & movie) const
{
	return (*this == movie) || (*this > movie);
}

//-----------------------------------------------------------------------------
// determines if two classic movies are the same
bool ClassicMovie::isEqual(const ClassicMovie * movie) const
{
	return identifier == movie->getIdentifier() && releaseYear == movie->getReleaseYear()
		&& releaseMonth == movie->getReleaseMonth() && actor == movie->getActor();
}

//-----------------------------------------------------------------------------
// determines if two classic movies are the same without 
// consideration for the actor name
bool ClassicMovie::isEqualNoActor(const ClassicMovie * movie) const
{
	return identifier == movie->getIdentifier() && releaseYear == movie->getReleaseYear()
		&& releaseMonth == movie->getReleaseMonth();
}

//-----------------------------------------------------------------------------
// determines if the current ClassicMovie instance is of
// less value than another
bool ClassicMovie::isLess(const ClassicMovie * movie) const
{
	if (releaseYear < movie->getReleaseYear())
	{
		return true;
	}
	else if (releaseYear == movie->getReleaseYear())
	{
		if (releaseMonth == movie->getReleaseMonth())
		{
			return actor < movie->getActor();
		}
		return releaseMonth < movie->getReleaseMonth();
	}
	return false;
}

//-----------------------------------------------------------------------------
// determines if the current ClassicMovie instance is of
// greater value than another
bool ClassicMovie::isGreater(const ClassicMovie * movie) const
{
	if (releaseYear > movie->getReleaseYear())
	{
		return true;
	}
	else if (releaseYear == movie->getReleaseYear())
	{
		if (releaseMonth == movie->getReleaseMonth())
		{
			return actor > movie->getActor();
		}
		return releaseMonth > movie->getReleaseMonth();
	}
	return false;
}
