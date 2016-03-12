#include "stdafx.h"
#include "MovieFactory.h"

Movie * MovieFactory::makeMovie(char argIndentifier)
{
	switch (argIndentifier)
	{
	case 'f':
		return new ComedyMovie();
	case 'c':
		return new ClassicMovie();
	case 'd':
		return new DramaMovie();
	default:
		return nullptr;
	}
}
