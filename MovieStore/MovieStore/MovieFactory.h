#pragma once
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include <vector>
#include <iostream>
using namespace std;

static class MovieFactory
{
public:
	static Movie* makeMovie(const vector<string> movieCreationInfo);
private:
	static vector<string> split(string stringToSplit, char separator);
	static vector<string> splitActorAndDate(string stringToSplit);
};

