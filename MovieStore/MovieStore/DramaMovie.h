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

private:
	char identifier = 'd';
};

