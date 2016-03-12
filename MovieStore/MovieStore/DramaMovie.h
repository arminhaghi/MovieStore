#pragma once
#include "Movie.h"
#include <string>
using namespace std;

class DramaMovie : public Movie
{
public:
	DramaMovie();
	DramaMovie(const Person &argDirector, const string &argTitle, const char &argType, const int &argYear);
	~DramaMovie();

	// Base pure virtual functions
	char getIdentifier() const;

private:
	char identifier = 'd';
};

