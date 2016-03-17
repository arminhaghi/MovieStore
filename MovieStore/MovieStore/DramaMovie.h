/*
A DramacMovie object holds a Movie of the Drama genre that is in
MovieStore

Authors: Kyle Burney, Armin Haghi
*/

#pragma once
#include "Movie.h"
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// DramaMovie: a Movie with drama genre
//
// Implementation and assumptions:
//
// -- Inherits from Movie class

class DramaMovie : public Movie
{
public:
	// creates instances of DramaMovie objects
	DramaMovie();
	DramaMovie(const string &argDirector, const string &argTitle, const char &argType, const int &argYear, const int &argAmount);
	~DramaMovie();

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
	// used to identify it is of drama genre
	char identifier = 'd';

	// determines if two drama movies are the same
	bool isEqual(const DramaMovie* movie) const;

	// determines if the current ComedyMovie instance is of
	// less value than another
	bool isLess(const DramaMovie* movie) const;

	// determines if the current ComedyMovie instance is of
	// greater value than another
	bool isGreater(const DramaMovie* movie) const;

};

