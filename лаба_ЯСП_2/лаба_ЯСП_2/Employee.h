#pragma once
#include "Date.h"

class Employee
{
	string employee_number;
	int department_number;
	string surname;
	double salary;
	Date date_of_admission;
	double percentage_of_bonus;
	double income_tax;
	int number_of_worked_days_in_month;
	int number_of_working_days_in_month;
	double accrued;
	double withheld;
public:
	Employee();
	Employee(const Employee& employee);

	friend bool operator== (const Employee& first, const Employee& second);
	friend ostream& operator<< (ostream& out, const Employee& employee);
	friend istream& operator>> (istream& in, Employee& employee);
	Employee& operator= (const Employee& employee);

	string toString() const;
	static bool compare_department_number(Employee first, Employee second);
	static bool compare_surname(Employee first, Employee second);
	static bool compare_date_of_admission(Employee first, Employee second);
	static bool compare_salary(Employee first, Employee second);

	string get_employee_number();
	int get_department_number();
	string get_surname();
	double get_salary();
	Date get_date_of_admission();
	double get_percentage_of_bonus();
	double get_income_tax();
	int get_number_of_days_worked_in_wonth();
	int get_number_of_working_days_in_wonth();
	double get_accrued();
	double get_withheld();

	void set_employee_number(string value);
	void set_department_number(int value);
	void set_surname(string value);
	void set_salary(double value);
	void set_date_of_admission(Date value);
	void set_percentage_of_bonus(double value);
	void set_income_tax(double info);
	void set_number_of_days_worked_in_wonth(int info);
	void set_number_of_working_days_in_wonth(int info);
	void set_accrued(double info);
	void set_withheld(double info);
};

