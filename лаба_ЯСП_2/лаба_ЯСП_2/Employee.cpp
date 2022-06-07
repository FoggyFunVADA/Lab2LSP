#include "Employee.h"

Employee::Employee():date_of_admission()
{
	employee_number = "";
	department_number = 0;
	surname = "";
	salary = 0.0;
	percentage_of_bonus = 0.0;
	income_tax = 0.0;
	number_of_worked_days_in_month = 0;
	number_of_working_days_in_month = 0;
	accrued = 0.0;
	withheld = 0.0;
}

Employee::Employee(const Employee& employee)
{
	employee_number = employee.employee_number;
	department_number = employee.department_number;
	surname = employee.surname;
	salary = employee.salary;
	date_of_admission = employee.date_of_admission;
	percentage_of_bonus = employee.percentage_of_bonus;
	income_tax = employee.income_tax;
	number_of_worked_days_in_month = employee.number_of_worked_days_in_month;
	number_of_working_days_in_month = employee.number_of_working_days_in_month;
	accrued = employee.accrued;
	withheld = employee.withheld;
}

bool operator==(const Employee& first, const Employee& second)
{
	return (first.department_number == second.department_number && first.surname == second.surname &&
		first.salary == second.salary && first.date_of_admission == second.date_of_admission);
}

ostream& operator<< (ostream& out, const Employee& employee)
{
	out << employee.employee_number << " " << employee.department_number << " " << employee.surname << " " << employee.salary << " " <<  employee.date_of_admission << " "
		<< employee.percentage_of_bonus << " " <<  employee.income_tax << " " << employee.number_of_worked_days_in_month << " " << employee.number_of_working_days_in_month << " "
		<< employee.accrued << " " << employee.withheld << "\n";
	return out;
}

istream& operator>> (istream& in, Employee& employee)
{
	in >> employee.employee_number;
	in >> employee.department_number;
	in >> employee.surname;
	in >> employee.salary;
	in >> employee.date_of_admission;
	in >> employee.percentage_of_bonus;
	in >> employee.income_tax;
	in >> employee.number_of_worked_days_in_month;
	in >> employee.number_of_working_days_in_month;
	in >> employee.accrued;
	in >> employee.withheld;
	return in;
}

Employee& Employee::operator= (const Employee& employee)
{
	employee_number = employee.employee_number;
	department_number = employee.department_number;
	surname = employee.surname;
	salary = employee.salary;
	date_of_admission = employee.date_of_admission;
	percentage_of_bonus = employee.percentage_of_bonus;
	income_tax = employee.income_tax;
	number_of_worked_days_in_month = employee.number_of_worked_days_in_month;
	number_of_working_days_in_month = employee.number_of_working_days_in_month;
	accrued = employee.accrued;
	withheld = employee.withheld;
	return *this;
}

string Employee::toString() const
{
	string result = "";
	stringstream ss;
	string tmp = "";
	ss << "Табельный номер: " << employee_number << "\nНомер отдела: " << department_number << "\nФамилия: "
		<< surname << "\nОклад: " << salary << "\nДата поступления на работу: " << date_of_admission <<
		"\nПроцент надбавки: " << percentage_of_bonus << "\nПодоходный налог: " << income_tax << "\nКоличество рабочих дней в месяце: " << number_of_working_days_in_month
		<< "\nКоличество отработанных дней в месяце: " << number_of_worked_days_in_month << "\nНачислено: " << accrued << "\nУдержано: " << withheld;
	while (getline(ss, tmp))
	{
		result += tmp + "\n";
	}
	return result;
}

bool Employee::compare_department_number(Employee first, Employee second)
{
	return first.department_number < second.department_number;
}

bool Employee::compare_surname(Employee first, Employee second)
{
	return strcmp(second.surname.c_str(), first.surname.c_str()) > 0;
}

bool Employee::compare_salary(Employee first, Employee second)
{
	return first.salary < second.salary;
}

bool Employee::compare_date_of_admission(Employee first, Employee second)
{
	return  first.date_of_admission < second.date_of_admission;
}



string Employee::get_employee_number()
{
	return employee_number;
}

int Employee::get_department_number()
{
	return department_number;
}

string Employee::get_surname()
{
	return surname;
}

double Employee::get_salary()
{
	return salary;
}

Date Employee::get_date_of_admission()
{
	return date_of_admission;
}

double Employee::get_percentage_of_bonus()
{
	return percentage_of_bonus;
}

double Employee::get_income_tax()
{
	return income_tax;
}

int Employee::get_number_of_days_worked_in_wonth()
{
	return number_of_worked_days_in_month;
}

int Employee::get_number_of_working_days_in_wonth()
{
	return number_of_working_days_in_month;
}

double Employee::get_accrued()
{
	return accrued;
}

double Employee::get_withheld()
{
	return withheld;
}



void Employee::set_employee_number(string value)
{
	employee_number = value;
}

void Employee::set_department_number(int value)
{
	department_number = value;
}

void Employee::set_surname(string value)
{
	surname = value;
}

void Employee::set_salary(double value)
{
	salary = value;
}

void Employee::set_date_of_admission(Date value)
{
	date_of_admission = value;
}

void Employee::set_percentage_of_bonus(double value)
{
	percentage_of_bonus = value;
}

void Employee::set_income_tax(double info)
{
	income_tax = info;
}

void Employee::set_number_of_days_worked_in_wonth(int info)
{
	number_of_worked_days_in_month = info;
}

void Employee::set_number_of_working_days_in_wonth(int info)
{
	number_of_working_days_in_month = info;
}

void Employee::set_accrued(double info)
{
	accrued = info;
}

void Employee::set_withheld(double info)
{
	withheld = info;
}