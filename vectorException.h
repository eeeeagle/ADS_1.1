#pragma once
#include <iostream>
using namespace std;

class vectorException
{
	const char* error;
public:
	vectorException(const char* str);
	void printError() const;
};