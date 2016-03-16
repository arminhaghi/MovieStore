#pragma once
#include "Movie.h"
#include <string>
using namespace std;

class DramaMovie : public Movie
{
public:
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
	char identifier = 'd';

	bool isEqual(const DramaMovie* movie) const;
	bool isLess(const DramaMovie* movie) const;
	bool isGreater(const DramaMovie* movie) const;

};

