#include "vector.h"
#include <cmath>

double vector::eps = 0.0001;

vector::vector(const int size, const double value)
	: size(size)
{
	data = new double[size];
	for (int i = 0; i < size; i++)
		data[i] = value;
}

vector::vector(const vector& v)
	: size(v.size)
{
	data = new double[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

vector::~vector()
{
	delete[] data;
}

double& vector::operator[](const int index)
{
	if (index < 0 || index >= size)
		throw vectorException("Invalid index");
	return data[index];
}

istream& operator>> (istream& is, vector& v)
{
	cout << "Dimension = ";
	is >> v.size;
	v.data = new double[v.size];
	for (int i = 0; i < v.size; i++)
	{
		cout << "V[" << i << "] = ";
		is >> v.data[i];
	}
	return is;
}

ostream& operator<< (ostream& os, const vector& v)
{
	os << "[";
	for (int i = 0; i < v.size; i++)
	{
		os << v.data[i];
		if(i != v.size - 1)
			os << " ";
	}
	os << "]";
	return os;
}

vector& vector::operator=(const vector& v)
{
	if (*this == v)
		return *this;
	delete[] data;
	data = new double[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}

vector vector::operator+(const vector& v)
{
	if (size != v.size)
		throw vectorException("Inequality of dimensions of vectors");
	vector res(*this);
	for (int i = 0; i < size; i++)
		res.data[i] += v.data[i];
	return res;
}

vector vector::operator-(const vector& v)
{
	if (size != v.size)
		throw vectorException("Inequality of dimensions of vectors");
	vector res(*this);
	for (int i = 0; i < size; i++)
		res.data[i] -= v.data[i];
	return res;
}

double vector::operator*(const vector& v)
{
	if (size != v.size)
		throw vectorException("Inequality of dimensions of vectors");
	double res = 0.0;
	for (int i = 0; i < size; i++)
		res += data[i] * v.data[i];
	return res;
}

vector vector::operator*(const double value)
{
	vector res(*this);
	for (int i = 0; i < size; i++)
		res[i] = data[i] * value;
	return res;
}

vector operator* (const double value, const vector& v)
{
	vector res(v);
	for (int i = 0; i < v.size; i++)
		res[i] *= value;
	return res;
}

vector vector::operator/ (const double value)
{
	if (value == 0.0)
		throw vectorException("Dividing to 0 is impossible");
	vector res(*this);
	for (int i = 0; i < size; i++)
		res[i] /= value;
	return res;
}

bool vector::operator==(const vector& v) const
{
	if (size != v.size)
		throw vectorException("Inequality of dimensions of vectors");
	for (int i = 0; i < size; i++)
	{
		if (fabs(data[i] - v.data[i]) >= eps)
			return false;
	}
	return true;
}

bool vector::operator!=(const vector& v) const
{
	if (size != v.size)
		throw vectorException("Inequality of dimensions of vectors");
	for (int i = 0; i < size; i++)
	{
		if (fabs(data[i] - v.data[i]) >= eps)
			return true;
	}
	return false;
}

const double vector::getEps()
{
	return eps;
}

void vector::setEps(const double value)
{
	if (value <= 0.0 || value >= 1.0)
		throw vectorException("eps should be in the range from 0.0 to 1.0");
	eps = value;
}