#include "stdafx.h"
#include "Person.h"

Person::Person()
{
	setName("");
}

Person::Person(const string & argName)
{
	setName(argName);
}

Person::~Person()
{
}

void Person::setName(const string &argName)
{
	name = argName;
}

string Person::getName() const
{
	return name;
}
