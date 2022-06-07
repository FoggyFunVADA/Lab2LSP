#pragma once
#include "Date.h"

Date::Date(const Date& date)
{
    day = date.day;
    month = date.month;
    year = date.year;
}

int Date::number_of_days_in_month()
{
    switch (month)
    {
    case 1:
    case 3:  
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return (year % 4 == 0) ? 29 : 28;
    default:
        return -1;
    }
}

bool Date::is_date() {

    if (!check_in_range(year, 1975, 2022))
        return false;
    switch (month)
    {
    case 1:
    case 3: 
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return check_in_range(day, 1, 31);
    case 4: 
    case 6:
    case 9: 
    case 11:
        return check_in_range(day, 1, 30);
    case 2:
        if (year % 4 == 0)
            return check_in_range(day, 1, 29);
        else
            return check_in_range(day, 1, 28);
    default:
        return false;
    }
}

string Date::toString() const
{
    stringstream ss;
    string tmp = "";
    ss << day << " " << month << " " << year;
    getline(ss, tmp);
    return tmp;
}

Date& Date::operator= (const Date& date)
{
    day = date.day;
    month = date.month;
    year = date.year;
    return *this;
}

bool operator< (const Date& first, const Date& second)
{
    return (first.year < second.year || first.year == second.year && first.month < second.month ||
        first.year == second.year && first.month == second.month && first.day < second.day);
}

bool operator> (const Date& first, const Date& second)
{
    return (first.year > second.year || first.year == second.year && first.month > second.month ||
        first.year == second.year && first.month == second.month && first.day > second.day);
}

bool operator<= (const Date& first, const Date& second)
{
    return (first.year < second.year || first.year == second.year && first.month < second.month ||
        first.year == second.year && first.month == second.month && first.day <= second.day);
}

bool operator== (const Date& first, const Date& second)
{
    return first.year == second.year && first.month == second.month && first.day == second.day;
}

ostream& operator<< (ostream& out, const Date& date)
{
    out << date.toString();
    return out;
}

istream& operator>> (istream& in, Date& date)
{
    in >> date.day;
    in >> date.month;
    in >> date.year;
    return in;
}