/*
A Movie object holds a Movie of the any genre that is in
MovieStore

Authors: Kyle Burney, Armin Haghi
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// Movie: a Movie with any genre
//
// Implementation and assumptions:
//
// -- Child classes will inherit from this
// -- A movie has identifiers such as Director,
// -- Title, Type, Release year, and an amount

class Movie
{
	// displays the Movie's information
	friend ostream& operator<<(ostream& os, const Movie &movie);
public:
	// creates an instance of the Movie class
	Movie();
	~Movie();
	
	// returns the name of the Director
	string getDirector() const;

	// returns the title of the Movie
	string getTitle() const;

	// returns the type of the Movie
	char getType() const;

	// returns the year the movie was released
	int getReleaseYear() const;

	// returns the stock for the movie
	int getStock() const;

	// updates the stock of the movie
	void updateStock(const int &amount);

	// increases the stock of the movie
	void increaseStock(const int amount);

	// sets the name of the director 
	void setDirector(const string &argPerson);

	// sets the title of the movie
	void setTile(const string &argTitle);

	// sets the year that the movie was released
	void setReleaseYear(const int &argYear);

	//Pure Virtual Functions
	virtual char getIdentifier() const = 0;

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
	//name of the director of the movie
	string director;

	//title of the movie
	string title;

	// type of the movie
	char type;

	//year the movie was released
	int releaseYear;

	//amount of copies MovieStore owns
	int stock;
};