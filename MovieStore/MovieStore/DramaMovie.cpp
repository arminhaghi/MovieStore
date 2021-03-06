#include "stdafx.h"
#include "DramaMovie.h"

//-----------------------------------------------------------------------------
// creates instances of DramaMovie objects
DramaMovie::DramaMovie()
{
	identifier = 'd';
}

DramaMovie::DramaMovie(const string& argDirector, const string & argTitle, const char & argType, const int & argYear, const int &argAmount)
{
	identifier = 'd';
	setDirector(argDirector);
	setTile(argTitle);
	type = argType;
	setReleaseYear(argYear);
	stock = argAmount;
}

DramaMovie::~DramaMovie()
{
}

//-----------------------------------------------------------------------------
// Base pure virtual functions
char DramaMovie::getIdentifier() const
{
	return identifier;
}

//-----------------------------------------------------------------------------
// Operator Functions
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
	if (identifier != movie.getIdentifier())
	{
		return identifier > movie.getIdentifier();
	}
	const DramaMovie* pMovie = dynamic_cast<const DramaMovie*>(&movie);
	if (pMovie != NULL)
	{
		return isLess(pMovie);
	}
	return false;
}

bool DramaMovie::operator>(const Movie & movie) const
{
	if (identifier != movie.getIdentifier())
	{
		return identifier < movie.getIdentifier();
	}
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

//-----------------------------------------------------------------------------
// determines if two drama movies are the same
bool DramaMovie::isEqual(const DramaMovie * movie) const
{
	return identifier == movie->getIdentifier() && director == movie->getDirector() 
		&& title == movie->getTitle();
}

//-----------------------------------------------------------------------------
// determines if the current ComedyMovie instance is of
// less value than another
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

//-----------------------------------------------------------------------------
// determines if the current ComedyMovie instance is of
// greater value than another
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
