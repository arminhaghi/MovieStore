// MovieStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include <iostream>
#include "MovieFactory.h"

int main()
{
	Movie* m;

	char c;
	while (true)
	{
		cin >> c;

		m = MovieFactory().makeMovie(c);

		m->setReleaseMonth(1);

		cout << m->getReleaseMonth() << endl;

		cout << m->getIdentifier() << endl;
	}

	return 0;
}

