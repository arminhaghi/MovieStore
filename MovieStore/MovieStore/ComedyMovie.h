#pragma once
#include "Movie.h"
#include <string>
using namespace std;

class ComedyMovie : public Movie
{
public:
	ComedyMovie();
	ComedyMovie(const string &argDirector, const string &argTitle, const char &argType, const int &argYear, const int &argAmount);
	~ComedyMovie();

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
	char identifier = 'f';

	bool isEqual(const ComedyMovie* movie) const;
	bool isLess(const ComedyMovie* movie) const;
	bool isGreater(const ComedyMovie* movie) const;
};

