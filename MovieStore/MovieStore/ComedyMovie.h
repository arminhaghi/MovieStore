#pragma once
#include "Movie.h"
#include <string>
using namespace std;

class ComedyMovie : public Movie
{
public:
	ComedyMovie();
	ComedyMovie(const Person &argDirector, const string &argTitle, const char &argType, const int &argYear);
	~ComedyMovie();

	// Base pure virtual functions
	char getIdentifier() const;

private:
	char identifier = 'f';
};

