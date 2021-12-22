#pragma once
#include "vectorException.h"
class vector
{
	int size;
	double* data;
	static double eps;
public:
	vector(const int size = 2, const double value = 0.0);
	vector(const vector& v);
	~vector();
	double& operator [] (const int index);
	friend istream& operator>> (istream& is, vector& v);
	friend ostream& operator<< (ostream& os, const vector& v);
	vector& operator = (const vector& v);
	vector operator + (const vector& v);
	vector operator - (const vector& v);
	double operator * (const vector& v);
	friend vector operator* (const double a, const vector& v);
	vector operator * (const double value);
	vector operator / (const double value);
	bool operator == (const vector& v) const;
	bool operator != (const vector& v) const;
	static const double getEps();
	static void setEps(const double value);
};