/*
A ClassicMovie object holds a Movie of the Classic genre that is in
MovieStore

Authors: Kyle Burney, Armin Haghi
*/

#pragma once
#include "Movie.h"
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// ClassicMovie: a Movie with classic genre
//
// Implementation and assumptions:
//
// -- Inherits from Movie class
// -- Every ClassicMovie has star Actors that can be used to identify what copy 
// -- the customer wants

class ClassicMovie : public Movie
{
public:
	// creates instances of ClassicMovie objects
	ClassicMovie();
	ClassicMovie(const string &argDirector, const string &argTitle, const string &argActor, const char &argType, const int &argYear, const int &argMonth, const int &argAmount);
	~ClassicMovie();

	// returns the name of the star actor
	string getActor() const;

	// sets the name of the star actor
	void setActor(const string &argActor);

	// returns the month the movie was released
	int getReleaseMonth() const;

	// sets the month the movie was released
	void setReleaseMonth(int argMonth);

	// Base pure virtual functions
	char getIdentifier() const;

	// Operator Functions
	bool operator==(const Movie &movie) const;
	bool operator!=(const Movie &movie) const;
	bool operator<=(const Movie &movie) const;
	bool operator<(const Movie &movie) const;
	bool operator>(const Movie &movie) const;
	bool operator>=(const Movie &movie) const;

private:
	// used to identify it is of classic genre
	char identifier;

	// holds the monthe the movie was released
	int releaseMonth;

	// holds the name of the main actor
	string actor;

	// determines if two classic movies are the same
	bool isEqual(const ClassicMovie* movie) const;

	// determines if two classic movies are the same without 
	// consideration for the actor name
	bool isEqualNoActor(const ClassicMovie* movie) const;

	// determines if the current ClassicMovie instance is of
	// less value than another
	bool isLess(const ClassicMovie* movie) const;

	// determines if the current ClassicMovie instance is of
	// greater value than another
	bool isGreater(const ClassicMovie* movie) const;
};

