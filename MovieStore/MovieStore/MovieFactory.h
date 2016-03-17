/*
A MovieFactory object is a class that is used to create Movie objects

Authors: Armin Haghi, Kyle Burney
*/

#pragma once
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// MovieFactory: a class that creates Movie objects
//
// Implementation and assumptions:
//
// -- can not be instantiated

static class MovieFactory
{
public:
	// creates Movie objects
	static Movie* makeMovie(const vector<string> movieCreationInfo);
private:
	// used to split lines of text from a file into useful information
	static vector<string> split(string stringToSplit, char separator);

	// used to split the data that combines the actor name and release date
	static vector<string> splitActorAndDate(string stringToSplit);
};
