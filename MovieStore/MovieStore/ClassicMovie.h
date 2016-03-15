#pragma once
#include "Movie.h"
#include <string>
using namespace std;

class ClassicMovie : public Movie
{
public:
	ClassicMovie();
	ClassicMovie(const string &argDirector, const string &argTitle, const string &argActor, const char &argType, const int &argYear, const int &argMonth, const int &argAmount);
	~ClassicMovie();

	string getActor();
	void setActor(const string &argActor);
	int getReleaseMonth();
	void setReleaseMonth(int argMonth);

	// Base pure virtual functions
	char getIdentifier() const;

private:
	char identifier = 'c';
	int releaseMonth;
	string actor;
};

