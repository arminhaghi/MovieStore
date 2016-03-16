#include "stdafx.h"
#include "DramaMovie.h"


DramaMovie::DramaMovie()
{
}

DramaMovie::DramaMovie(const string& argDirector, const string & argTitle, const char & argType, const int & argYear, const int &argAmount)
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

bool DramaMovie::operator==(const Movie &movie) const
{
	const DramaMovie* pMovie = dynamic_cast<const DramaMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isEqual(pMovie);
	}
	return false;
}

bool DramaMovie::operator!=(const Movie & movie) const
{
	const DramaMovie* pMovie = dynamic_cast<const DramaMovie*>(&movie);
	if (pMovie != NULL)
	{
		return !isEqual(pMovie);
	}
	return false;
}

bool DramaMovie::operator<=(const Movie & movie) const
{
	return (*this == movie) || (*this < movie);
}

bool DramaMovie::operator<(const Movie & movie) const
{
	const DramaMovie* pMovie = dynamic_cast<const DramaMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isLess(pMovie);
	}
	return false;
}

bool DramaMovie::operator>(const Movie & movie) const
{
	const DramaMovie* pMovie = dynamic_cast<const DramaMovie*>(&movie);
	if (pMovie != NULL)
	{
		return  isGreater(pMovie);
	}
	return false;
}

bool DramaMovie::operator>=(const Movie & movie) const
{
	return (*this == movie) || (*this > movie);
}

bool DramaMovie::isEqual(const DramaMovie * movie) const
{
	return identifier == movie->getIdentifier() && director == movie->getDirector() 
		&& title == movie->getTitle();
}

bool DramaMovie::isLess(const DramaMovie * movie) const
{
	if (director > movie->getDirector())
	{
		return false;
	}
	else if (director < movie->getDirector())
	{
		return true;
	}
	else if (title < movie->getTitle())
	{
		return true;
	}
	return false;
}

bool DramaMovie::isGreater(const DramaMovie * movie) const
{
	if (director < movie->getDirector())
	{
		return false;
	}
	else if (director > movie->getDirector())
	{
		return true;
	}
	else if (title > movie->getTitle())
	{
		return true;
	}
	return false;
}
