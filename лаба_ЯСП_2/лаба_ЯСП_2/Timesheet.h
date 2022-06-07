#pragma once
#include "Employee.h"
#include <vector>
#include <algorithm>

template <class T>
class Timesheet
{
	vector<T> timesheet;
public:
	int get_size()
	{
		return timesheet.size();
	}
	
	void clear()
	{
		timesheet.clear();
	}

	vector<T> get_timesheet()
	{
		return timesheet;
	}

	T& operator[](int number)
	{
		return *(timesheet.begin() + number);
	}

	void add_note(T note)
	{
		timesheet.emplace_back(note);
	}

	void add_notes_with_iter(istream_iterator<T> in)
	{
		istream_iterator<T> tmp;
		while (in != tmp)
		{
			timesheet.emplace_back(*in++);
		}
	}
	
	void delete_note(int number)
	{
		timesheet.erase(timesheet.begin() + number);
	}

	void print_notes_in_console()
	{
		if (timesheet.size() == 0)
			cout << "\nКонтейнер пуст!\n";
		else
		{
			int count = 0;
			for (auto it : timesheet)
			{
				cout << "Номер: " << count << "\n" << it.toString() << "\n";
				count++;
			}
		}
	}

	void print(ostream_iterator<T> out)
	{
		for (auto it : timesheet)
		{
			*out++ = it;
		}
	}

	template<class P>
	bool find(const P& predicate)
	{
		return find_if(timesheet.begin(), timesheet.end(), predicate) != timesheet.end();
	}

	bool binary_find(bool(*comparator)(T, T), T value)
	{
		sort(timesheet.begin(), timesheet.end(), comparator);
		return binary_search(timesheet.begin(), timesheet.end(), value, comparator);
	}

	template<class P>
	Timesheet<T> find_set(const P& predicate)
	{
		Timesheet<T> result;
		auto left = timesheet.begin();
		auto right = timesheet.end();
		while (left != right)
		{
			left = find_if(left, right, predicate);
			if (left != right)
			{
				result.add_note(*left);
				left++;
			}
		}
		return result;
	}

	Timesheet<T> binary_set_find(bool(*comparator)(T, T), T value)
	{
		Timesheet<T> result;
		sort(timesheet.begin(), timesheet.end(), comparator);
		auto edges = equal_range(timesheet.begin(), timesheet.end(), value, comparator);
		while (edges.first != edges.second)
		{
			result.add_note(*edges.first);
			edges.first++;
		}
		return result;
	}
};
