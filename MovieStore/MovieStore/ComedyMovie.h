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
// ComedyMovie: a Movie with comedy genre
//
// Implementation and assumptions:
//
// -- Inherits from Movie class

class ComedyMovie : public Movie
{
public:
	// creates instances of ComedyMovie objects
	ComedyMovie();
	ComedyMovie(const string &argDirector, const string &argTitle, const char &argType, const int &argYear, const int &argAmount);
	~ComedyMovie();

	// Base pure virtual function
	char getIdentifier() const;

	// Operator Functions
	bool operator==(const Movie &movie) const;
	bool operator!=(const Movie &movie) const;
	bool operator<=(const Movie &movie) const;
	bool operator<(const Movie &movie) const;
	bool operator>(const Movie &movie) const;
	bool operator>=(const Movie &movie) const;

private:
	// used to identify it is of comedy genre
	char identifier = 'f';

	// determines if two comedy movies are the same
	bool isEqual(const ComedyMovie* movie) const;

	// determines if the current ComedyMovie instance is of
	// less value than another
	bool isLess(const ComedyMovie* movie) const;

	// determines if the current ComedyMovie instance is of
	// greater value than another
	bool isGreater(const ComedyMovie* movie) const;
};

