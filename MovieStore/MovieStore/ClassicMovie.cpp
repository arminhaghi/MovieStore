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
	stock = argAmount;
}


ClassicMovie::~ClassicMovie()
{
}

string ClassicMovie::getActor() const
{
	return actor;
}

void ClassicMovie::setActor(const string & argActor)
{
	actor = argActor;
}

int ClassicMovie::getReleaseMonth() const
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
	const ClassicMovie* pMovie = dynamic_cast<const ClassicMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isLess(pMovie);
	}
	return false;
}

bool ClassicMovie::operator>(const Movie & movie) const
{
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

bool ClassicMovie::isEqual(const ClassicMovie * movie) const
{
	return identifier == movie->getIdentifier() && releaseYear == movie->getReleaseYear()
		&& releaseMonth == movie->getReleaseMonth() && actor == movie->getActor();
}

bool ClassicMovie::isEqualNoActor(const ClassicMovie * movie) const
{
	return identifier == movie->getIdentifier() && releaseYear == movie->getReleaseYear()
		&& releaseMonth == movie->getReleaseMonth();
}

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
