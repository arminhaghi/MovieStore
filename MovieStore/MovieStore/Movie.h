#pragma once
#include <string>
using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& os, const Movie &movie);
public:
	Movie();
	//Movie(const Person &argDirector, const string &argTitle, const char &argType, const int &argYear);
	~Movie();
	
	string getDirector() const;
	string getTitle() const;
	char getType() const;
	int getReleaseYear() const;
	int getStock() const;
	void increaseStock(const int amount);

	void setDirector(const string &argPerson);
	void setTile(const string &argTitle);
	void setReleaseYear(const int &argYear);

	//Pure Virtual Functions
	virtual char getIdentifier() const = 0;

	// To Do:  Remove these from here, in case it doesn't break things.
	//Classic Movie Virtual Functions
	virtual string getActor() const;
	virtual int getReleaseMonth() const;
	virtual void setReleaseMonth(int argMonth);

	//Operator Functions
	virtual bool operator==(const Movie &movie) const = 0;
	virtual bool operator!=(const Movie &movie) const = 0;
	virtual bool operator<=(const Movie &movie) const = 0;
	virtual bool operator<(const Movie &movie) const = 0;
	virtual bool operator>(const Movie &movie) const = 0;
	virtual bool operator>=(const Movie &movie) const = 0;


protected:
	string director;
	string title;
	char type;
	int releaseYear;
	int stock;
};