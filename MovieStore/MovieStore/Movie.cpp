#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
}

//Movie::Movie(const char & argIndentifier, const Person & argDirector, const string & argTitle, const char & argType, const int & argYear)
//{
//	identifier = argIndentifier;
//	setDirector(argDirector);
//	setTile(argTitle);
//	type = argType;
//	setReleaseYear(argYear);
//}


Movie::~Movie()
{
}

string Movie::getDirector() const
{
	return director;
}

string Movie::getTitle() const
{
	return title;
}

char Movie::getType() const
{
	return type;
}

int Movie::getReleaseYear() const
{
	return releaseYear;
}

int Movie::getStock() const
{
	return stock;
}

void Movie::updateStock(const int & amount)
{
	stock += amount;
}

void Movie::increaseStock(const int amount)
{
	stock += amount;
}

void Movie::setDirector(const string & argPerson)
{
	director = argPerson;
}

void Movie::setTile(const string & argTitle)
{
	title = argTitle;
}

void Movie::setReleaseYear(const int & argYear)
{
	releaseYear = argYear;
}

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