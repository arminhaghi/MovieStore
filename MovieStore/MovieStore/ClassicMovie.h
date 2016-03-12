#pragma once
#include "Movie.h"
#include "Person.h"
#include <string>
using namespace std;

class ClassicMovie : public Movie
{
public:
	ClassicMovie();
	ClassicMovie(const Person &argDirector, const string &argTitle, const Person &argActor, const char &argType, const int &argYear, const int &argMonth);
	~ClassicMovie();

	Person getActor();
	void setActor(const Person &argActor);
	int getReleaseMonth();
	void setReleaseMonth(int argMonth);

	// Base pure virtual functions
	char getIdentifier() const;

private:
	char identifier = 'c';
	int releaseMonth;
	Person actor;
};

