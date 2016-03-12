#pragma once
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"

static class MovieFactory
{
public:
	static Movie* makeMovie(char argIndentifier);
};

