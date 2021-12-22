#include "vectorException.h"

vectorException::vectorException(const char* msg)
	: error(msg) 
{}

void vectorException::printError() const
{
	cout << error << endl;
}