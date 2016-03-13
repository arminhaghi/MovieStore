#pragma once
#include <iostream>
#include <fstream>
#include "MovieFactory.h"
#include "TransactionFactory.h"
using namespace std;

class FileReader
{
public:
	FileReader();
	~FileReader();

	void ReadData4Movies(const string &argFileName);
	void ReadData4Customers(const string &argFileName);
	void ReadData4Commands(const string &argFileName);
};

