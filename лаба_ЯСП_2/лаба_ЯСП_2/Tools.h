#pragma once

#include <iostream>

using namespace std;

template<class T>
bool check_in_range(T value, T left, T right)
{
	return (value >= left && value <= right);
}

int input_int();
double input_double();

template<class T>
T input_info_in_range(T left, T right)
{
	T result;
	cin >> result;
	while (!cin.good() || !check_in_range(result, left, right))
	{
		cin.clear();
		cin.ignore(255, '\n');
		cout << "«начение было введено некорректно!\n¬ведите значение в диапазоне от " << left << " до " << right << ": ";
		cin >> result;
	}
	return result;
}

string input_string();