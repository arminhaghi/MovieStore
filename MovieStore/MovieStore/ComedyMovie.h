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

private:
	char identifier = 'f';
};

