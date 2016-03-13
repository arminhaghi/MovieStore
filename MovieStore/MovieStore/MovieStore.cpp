// MovieStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include <iostream>
#include "MovieFactory.h"
#include "FileReader.h"

int main()
{
	FileReader fileReader;
	fileReader.ReadData4Movies("data4movies.txt");
	fileReader.ReadData4Commands("data4commands.txt");
	return 0;
}
