#include "vector.h"

int main()
{
	vector a;
	cout << "Fill vector a" << endl;
	cin >> a;
	system("cls");
	
	vector b;
	cout << "Fill vector b" << endl;
	cin >> b;
	
	bool flag = true;
	while (flag)
	{
		system("cls");
		double value = 0.0;
		cout << "Enter eps = ";
		cin >> value;
		try
		{
			vector::setEps(value);
			flag = false;
		}
		catch (vectorException& err)
		{
			err.printError();
		}
	}
	
	system("cls");
	cout << "Vector a = " << a << endl;
	cout << "Vector b = " << b << endl;
	cout << "eps = " << vector::getEps() << endl << "_____________________________________" << endl << endl;
	
	try
	{
		cout << "a[0] = " << a[0] << endl;
		cout << "b[2] = " << b[2] << endl << endl;
	}
	catch (vectorException& err)
	{
		err.printError();
	}

	try
	{
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	if (a == b)
		cout << "Vector a is equal vector b" << endl;
	if (a != b)
		cout << "Vector a isn't equal vector b" << endl;
	}
	catch (vectorException& err)
	{
		err.printError();
	}

	cout << endl << "a * 1.5 = " << a * 1.5 << endl;
	cout << "4.3 * b = " << 4.3 * b << endl;
	cout << "a / 6.0 = " << a / 6.0 << endl << "_____________________________________";
	
	return 0;
}