#include "stdafx.h"
#include "Movie.h"

//-----------------------------------------------------------------------------
// creates an instance of the Movie class
Movie::Movie()
{
}

Movie::~Movie()
{
}

//-----------------------------------------------------------------------------
// returns the name of the Director
string Movie::getDirector() const
{
	return director;
}

//-----------------------------------------------------------------------------
// returns the title of the Movie
string Movie::getTitle() const
{
	return title;
}

//-----------------------------------------------------------------------------
// returns the type of the Movie
char Movie::getType() const
{
	return type;
}

//-----------------------------------------------------------------------------
// returns the year the movie was released
int Movie::getReleaseYear() const
{
	return releaseYear;
}

//-----------------------------------------------------------------------------
// returns the stock for the movie
int Movie::getStock() const
{
	return stock;
}

//-----------------------------------------------------------------------------
// updates the stock of the movie
void Movie::updateStock(const int & amount)
{
	stock += amount;
}

//-----------------------------------------------------------------------------
// increases the stock of the movie
void Movie::increaseStock(const int amount)
{
	stock += amount;
}

//-----------------------------------------------------------------------------
// sets the name of the director 
void Movie::setDirector(const string & argPerson)
{
	director = argPerson;
}

//-----------------------------------------------------------------------------
// sets the title of the movie
void Movie::setTile(const string & argTitle)
{
	title = argTitle;
}

//-----------------------------------------------------------------------------
// sets the year that the movie was released
void Movie::setReleaseYear(const int & argYear)
{
	releaseYear = argYear;
}

//-----------------------------------------------------------------------------
//Classic Movie Virtual Functions
string Movie::getActor() const
{
	return "";
}

int Movie::getReleaseMonth() const
{
	return -1;
}

void Movie::setReleaseMonth(int argMonth)
{
}

//-----------------------------------------------------------------------------
// displays the Movie's information
ostream& operator<<(ostream& os, const Movie &movie)
{
	os << "Title: " << movie.getTitle() << "\t" << "Genre: " << movie.getIdentifier() << "\t" << "Year: " << movie.getReleaseYear() << "\t";
	if (movie.getActor() != "")
	{
		os << "Main Actor: " << movie.getActor() << "\t";
	}
	os << "Stock: " << movie.getStock() << endl << endl;
	return os;
}