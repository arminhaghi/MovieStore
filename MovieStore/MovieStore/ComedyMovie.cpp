#include "stdafx.h"
#include "ComedyMovie.h"


ComedyMovie::ComedyMovie()
{
}

ComedyMovie::ComedyMovie(const string & argDirector, const string & argTitle, const char & argType, const int & argYear, const int &argAmount)
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

bool ComedyMovie::operator==(const Movie & movie) const
{
	const ComedyMovie* pMovie = dynamic_cast<const ComedyMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isEqual(pMovie);
	}
	return false;

}

bool ComedyMovie::operator!=(const Movie & movie) const
{
	const ComedyMovie* pMovie = dynamic_cast<const ComedyMovie*>(&movie);
	if (pMovie != NULL)
	{
		return !isEqual(pMovie);
	}
	return false;

}

bool ComedyMovie::operator<=(const Movie & movie) const
{
	return (*this == movie) || (*this < movie);
}

bool ComedyMovie::operator<(const Movie & movie) const
{
	const ComedyMovie* pMovie = dynamic_cast<const ComedyMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isLess(pMovie);
	}
	return false;
}

bool ComedyMovie::operator>(const Movie & movie) const
{
	const ComedyMovie* pMovie = dynamic_cast<const ComedyMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isGreater(pMovie);
	}
	return false;
}

bool ComedyMovie::operator>=(const Movie & movie) const
{
	return (*this == movie) || (*this > movie);
}

bool ComedyMovie::isEqual(const ComedyMovie * movie) const
{
	return identifier == movie->getIdentifier() && title == movie->getTitle()
		&& releaseYear == movie->getReleaseYear();
}

bool ComedyMovie::isLess(const ComedyMovie * movie) const
{
	if (title > movie->getTitle())
	{
		return false;
	}
	else if (title < movie->getTitle())
	{
		return true;
	}
	else if (releaseYear < movie->getReleaseYear())
	{
		return true;
	}
	return false;
}

bool ComedyMovie::isGreater(const ComedyMovie * movie) const
{
	if (title < movie->getTitle())
	{
		return false;
	}
	else if (title > movie->getTitle())
	{
		return true;
	}
	else if (releaseYear > movie->getReleaseYear())
	{
		return true;
	}
	return false;
}
