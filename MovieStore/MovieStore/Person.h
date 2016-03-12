#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person();
	Person(string &argFirstname, string &argLastname);
	~Person();

	void setFirstname(const string &argFirstname);
	void setLastname(const string &argLastname);

	string getFirstname() const;
	string getLastname() const;
	string getFullname() const;

private:
	string firstname;
	string lastname;
};

