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

	string getActor() const;
	void setActor(const string &argActor);
	int getReleaseMonth() const;
	void setReleaseMonth(int argMonth);

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
	char identifier = 'c';
	int releaseMonth;
	string actor;

	bool isEqual(const ClassicMovie* movie) const;
	bool isEqualNoActor(const ClassicMovie* movie) const;
	bool isLess(const ClassicMovie* movie) const;
	bool isGreater(const ClassicMovie* movie) const;
};

