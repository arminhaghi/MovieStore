#pragma once
#include <string>
using namespace std;

class Movie
{
public:
	Movie();
	//Movie(const Person &argDirector, const string &argTitle, const char &argType, const int &argYear);
	~Movie();
	
	string getDirector() const;
	string getTitle() const;
	char getType() const;
	int getReleaseYear() const;
	int getStock() const;

	void setDirector(const string &argPerson);
	void setTile(const string &argTitle);
	void setReleaseYear(const int &argYear);

	//Pure Virtual Functions
	virtual char getIdentifier() const = 0;

	//Classic Movie Virtual Functions
	virtual string getActor();
	virtual int getReleaseMonth();
	virtual void setReleaseMonth(int argMonth);

protected:
	string director;
	string title;
	char type;
	int releaseYear;
	int stock;
};