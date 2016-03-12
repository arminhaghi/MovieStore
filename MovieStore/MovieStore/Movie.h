#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Movie
{
public:
	Movie();
	//Movie(const Person &argDirector, const string &argTitle, const char &argType, const int &argYear);
	~Movie();
	
	Person getDirector() const;
	string getTitle() const;
	char getType() const;
	int getReleaseYear() const;

	void setDirector(const Person &argPerson);
	void setTile(const string &argTitle);
	void setReleaseYear(const int &argYear);

	//Pure Virtual Functions
	virtual char getIdentifier() const = 0;

	//Classic Movie Virtual Functions
	virtual Person getActor();
	virtual int getReleaseMonth();
	virtual void setReleaseMonth(int argMonth);

protected:
	Person director;
	string title;
	char type;
	int releaseYear;
};