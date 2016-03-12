#include "stdafx.h"
#include "Person.h"

Person::Person()
{
	setFirstname("");
	setLastname("");
}

Person::Person(string & argFirstname, string & argLastname)
{
	setFirstname(argFirstname);
	setLastname(argLastname);
}


Person::~Person()
{
}

void Person::setFirstname(const string &argFirstname)
{
	firstname = argFirstname;
}

void Person::setLastname(const string &argLastname)
{
	lastname = argLastname;
}

string Person::getFirstname() const
{
	return firstname;
}

string Person::getLastname() const
{
	return lastname;
}

string Person::getFullname() const
{
	return getFirstname() + " " + getLastname();
}
