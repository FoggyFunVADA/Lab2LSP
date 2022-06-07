#pragma once

#include "Tools.h"
#include <sstream>

class Date {
	int day;
	int month;
	int year;
public:
	Date() : day(1), month(1), year(1975) {};
	Date(int day, int month, int year) : day(day), month(month), year(year) {};
	Date(const Date& date);

	int number_of_days_in_month();
	bool is_date();
	string toString() const;

	Date& operator=(const Date& date);
	friend bool operator< (const Date& first, const Date& second);
	friend bool operator> (const Date& first, const Date& second);
	friend bool operator<= (const Date& first, const Date& second);
	friend bool operator== (const Date& first, const Date& second);
	friend ostream& operator<< (ostream& out, const Date& date);
	friend istream& operator>> (istream& in, Date& date);

	int get_day() { return day; };
	int get_month() { return month; };
	int get_year() { return year; };

	void set_day(int day) { this->day = day; };
	void set_month(int month) { this->month = month; };
	void set_year(int year) { this->year = year; };
};