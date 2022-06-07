#include "Tools.h"

int input_int()
{
	int result;
	cin >> result;
	while (!cin.good() && result < 0)
	{
		cin.clear();
		cin.ignore(255, '\n');
		cout << "«начение было введено некорректно!\n¬ведите целое число: ";
		cin >> result;
	}
	return result;
}

string input_string()
{
	string result;
	cin >> result;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(255, '\n');
		cout << "«начение было введено некорректно!\n¬ведите строку: ";
		cin >> result;
	}
	return result;
}

double input_double()
{
	double result;
	cin >> result;
	while (!cin.good() && result < 0)
	{
		cin.clear();
		cin.ignore(255, '\n');
		cout << "«начение было введено некорректно!\n¬ведите вещественное число: ";
		cin >> result;
	}
	return result;
}
