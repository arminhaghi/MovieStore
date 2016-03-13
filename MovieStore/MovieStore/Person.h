#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person();
	Person(const string &name);
	~Person();

	void setName(const string &argname);

	string getName() const;

private:
	string name;
};

