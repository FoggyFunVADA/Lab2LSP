// Задача 6

// Результатом должна быть консольная программа с текстовым меню. Программа должна содержать шаблонный класс для управления данными согласно заданию.
// Для хранения данных необходимо выбрать оптимальный с точки зрения задания контейнер.

//  1. Предусмотреть операции добавления, изменения и удаления элемента контейнера.
//  2. Реализовать ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл.
//  3. Реализовать операции поиска по заданным критериям и выборки подмножества элементов по заданным критериям. 
//     Реализовать поиск в двух вариантах : линейный поиск и двоичный поиск на отсортированном контейнере.
//  4. Предусмотреть вывод подмножества выборки на экран и в файл.

// Задание:
// Информация о сотруднике представлена записью с полями : табельный номер, номер отдела, фамилия, оклад, дата поступления на работу, процент надбавки, 
// подоходный налог, количество отработанных дней в месяце, количество рабочих дней в месяце, начислено, удержано.
// Поиск по номеру отдела, фамилии, дате поступления и окладу.

#include "Timesheet.h"
#include <Windows.h>
#include <fstream>

void fill_employee(Employee&);
Date input_date();
void edit_employee(Timesheet<Employee>&);
void edit_or_add_info_in_cur_date(Employee&);
void main_menu();
void iterator_menu(Timesheet<Employee>&);
void find_menu(Timesheet<Employee>&);
void binary_find_menu(Timesheet<Employee>&);
void note_print_menu(Timesheet<Employee>&);
void find_set_menu(Timesheet<Employee>&);
void binary_find_set_menu(Timesheet<Employee>&);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	main_menu();
}

void main_menu()
{
	Timesheet<Employee> timesheet;
	int choice;
	do
	{
		cout << "\nВыберите необходимое действие в меню: \n";
		cout << "[0] Завершение работы программы...\n";
		cout << "[1] Ввод и вывод с помощью потоковых итераторов\n";
		cout << "[2] Вывести записи\n";
		cout << "[3] Добавить запись\n";
		cout << "[4] Изменить запись\n";
		cout << "[5] Удалить запись\n";
		cout << "[6] Линейный поиск по заданным критериям\n";
		cout << "[7] Бинарный поиск по заданным критериям\n";
		cout << "[8] Выборка подмножества по заданным критериям\n";
		cout << "[9] Бинарная выборка подмножества по заданным критериям\n";
		cout << "[10] Очистить контейнер\n";

		choice = input_info_in_range(0, 10);
		switch (choice)
		{
		case 1:
		{
			iterator_menu(timesheet);
			break;
		}
		case 2:
		{
			cout << "\n";
			timesheet.print_notes_in_console();
			cout << "\nДействие завершено\n";
			break;
		}
		case 3:
		{
			Employee employee;
			fill_employee(employee);
			timesheet.add_note(employee);
			cout << "\nДействие завершено\n";
			break;
		}
		case 4:
		{
			if (timesheet.get_size() == 0)
				cout << "\nКонтейнер пуст!\n";
			else
			{
				edit_employee(timesheet);
			}
			cout << "\nДействие завершено\n";
			break;
		}
		case 5:
		{
			if (timesheet.get_size() == 0)
				cout << "\nКонтейнер пуст!\n";
			else
			{
				cout << "\nВведите номер записи, которую нужно удалить: ";
				int number;
				number = input_info_in_range(0, timesheet.get_size() - 1);
				timesheet.delete_note(number);
			}
			cout << "\nДействие завершено\n";
			break;
		}
		case 6:
		{
			if (!timesheet.get_size())
				cout << "\nКонтейнер пуст!\n";
			else
				find_menu(timesheet);
			break;
		}
		case 7:
		{
			if (!timesheet.get_size())
				cout << "\nКонтейнер пуст!\n";
			else
				binary_find_menu(timesheet);
			break;
		}
		case 8:
		{
			if (!timesheet.get_size())
				cout << "\nКонтейнер пуст!\n";
			else
				find_set_menu(timesheet);
			break;
		}
		case 9:
		{
			if (!timesheet.get_size())
				cout << "\nКонтейнер пуст!\n"; 
			else
				binary_find_set_menu(timesheet);
			break;
		}
		case 10:
		{
			if (!timesheet.get_size())
				cout << "\nКонтейнер уже пуст!\n";
			else
			{
				timesheet.clear();
				cout << "\nДействие завершено!\n";
			}
			break;
		}
		}
	} while (choice != 0);
}

Date input_date()
{
	Date tmp;
	do
	{
		cout << "\nГод: ";
		tmp.set_year(input_int());
		cout << "Месяц: ";
		tmp.set_month(input_int());
		cout << "День: ";
		tmp.set_day(input_int());
		if (!tmp.is_date())
			cout << "\nНеправильный ввод данных! Повторите ввод!\n";
	} while (!tmp.is_date());
	return tmp;
}


void fill_employee(Employee& employee) 
{
	cout << "\n\n";
	cout << "Табельный номер: ";
	employee.set_employee_number(input_string());
	cout << "Номер отдела: ";
	employee.set_department_number(input_int());
	cout << "Фамилия: ";
	employee.set_surname(input_string());
	cout << "Оклад: ";
	employee.set_salary(input_double());
	cout << "Дата поступления на работу: ";
	cin.ignore(255, '\n');
	employee.set_date_of_admission(input_date());
	cout << "Процент надбавки: ";
	employee.set_percentage_of_bonus(input_double());
	cout << "Подоходный налог: ";
	employee.set_income_tax(input_info_in_range(0.0, 13.0));
	edit_or_add_info_in_cur_date(employee);
	cout << "Начислено: ";
	employee.set_accrued(input_double());
	cout << "Удержано: ";
	employee.set_withheld(input_double());
}

void edit_employee(Timesheet<Employee>& timesheet)
{
	cout << "\nВведите номер записи, которую нужно изменить: ";
	int number = input_info_in_range(0, timesheet.get_size() - 1);
	int choice;
	do
	{
		cout << "\nВыберите поле, которое необходимо изменить в записи\n";
		cout << "[0] Выход в главное меню\n";
		cout << "[1] Табельный номер\n";
		cout << "[2] Номер отдела\n";
		cout << "[3] Фамилия\n";
		cout << "[4] Оклад\n";
		cout << "[5] Дата поступления на работу\n";
		cout << "[6] Процент надбавки\n";
		cout << "[7] Подоходный налог\n";
		cout << "[8] Количество отработанных дней в месяце\n";
		cout << "[9] Количество рабочих дней в месяце\n";
		cout << "[10] Начислено\n";
		cout << "[11] Удержано\n";
		cout << "[12] Изменить все данные, связанные с текущим месяцем\n";

		choice = input_info_in_range(0, 12);
		cout << "\nВведите новые данные: ";
		switch (choice)
		{
		case 1:
		{
			timesheet[number].set_employee_number(input_string());
			break;
		}
		case 2:
		{
			timesheet[number].set_department_number(input_int());
			break;
		}
		case 3:
		{
			timesheet[number].set_surname(input_string());
			break;
		}
		case 4:
		{
			timesheet[number].set_salary(input_double());
			break;
		}
		case 5:
		{
			timesheet[number].set_date_of_admission(input_date());
			break;
		}
		case 6:
		{
			timesheet[number].set_percentage_of_bonus(input_double());
			break;
		}
		case 7:
		{
			timesheet[number].set_income_tax(input_double());
			break;
		}
		case 8:
		{
			timesheet[number].set_number_of_days_worked_in_wonth(input_int());
			break;
		}
		case 9:
		{
			timesheet[number].set_number_of_working_days_in_wonth(input_int());
			break;
		}
		case 10:
		{
			timesheet[number].set_accrued(input_double());
			break;
		}
		case 11:
		{
			timesheet[number].set_withheld(input_double());
			break;
		}
		case 12:
		{
			edit_or_add_info_in_cur_date(timesheet[number]);
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}

void edit_or_add_info_in_cur_date(Employee& employee)
{
	cout << "Введите дату для ввода данных о текущем месяце:\n";
	cin.ignore(255, '\n');
	Date cur_date = input_date();
	while (cur_date <= employee.get_date_of_admission())
	{
		cout << "Ошибка! Текущая дата меньше даты поступления на работу! Повторите ввод!\n";
		cur_date = input_date();
	}

	cout << "Количество рабочих дней в текущем месяце: ";
	employee.set_number_of_working_days_in_wonth(input_info_in_range(0, cur_date.number_of_days_in_month()));
	cout << "Количество отработанных дней в текущем месяце: ";
	employee.set_number_of_days_worked_in_wonth(input_info_in_range(0, cur_date.get_day()));
}

void iterator_menu(Timesheet<Employee>& timesheet)
{
	int choice;
	do
	{
		cout << "\nВыберите действие в меню:\n";
		cout << "[0] Вернуться в главное меню\n";
		cout << "[1] Вывести записи в консоль\n";
		cout << "[2] Вывести записи в файл\n";
		cout << "[3] Ввести записи из консоли\n";
		cout << "[4] Ввести записи из файла\n";
		choice = input_info_in_range(0, 4);
		switch (choice)
		{
		case 1:
		{
			cout << "\n";
			timesheet.print(cout);
			break;
		}
		case 2:
		{
			cout << "\nВведите имя файла: ";
			string file_name;
			cin >> file_name;
			ofstream file(file_name);
			timesheet.print(file);
			file.close();
			break;
		}
		case 3:
		{
			cout << "\nТабельный номер, номер отдела, фамилия, оклад, дата поступления на работу, процент надбавки,\n";
			cout << "подоходный налог, количество отработанных дней в месяце, количество рабочих дней в месяце, начислено, удержано\n";
			timesheet.add_notes_with_iter(cin);
			cout << "\nДля продолжения нажмите <Enter>\n";
			cin.clear();
			cin.ignore(255, '\n').get();
			break;
		}
		case 4:
		{
			cout << "\nВведите имя файла: ";
			string file_name;
			cin >> file_name;
			ifstream file(file_name);
			if (!file.is_open())
			{
				cout << "\nНе удалось открыть файл!\n";
				break;
			}
			timesheet.add_notes_with_iter(file);
			file.close();
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}

void find_menu(Timesheet<Employee>& timesheet)
{
	int choice;
	do
	{
		cout << "\nВыберите по какому параметру необходимо выполнить поиск: \n";
		cout << "[0] Выход в главное меню\n";
		cout << "[1] Номер отдела\n";
		cout << "[2] Фамилия\n";
		cout << "[3] Дата поступления\n";
		cout << "[4] Оклад\n";
		choice = input_info_in_range(0, 4);
		switch (choice)
		{
		case 1:
		{
			cout << "\nВведите номер отдела: ";
			int department_number = input_int();
			bool result = timesheet.find([department_number](Employee elem) {return elem.get_department_number() == department_number; });
			(result)? cout << "\nЗапись с данным номером отдела найдена!\n" : cout << "\nЗаписи с данным номером отдела в контейнере нет!\n";
			break;
		}
		case 2:
		{
			cout << "\nВведите фамилию: ";
			string surname;
			cin >> surname;
			bool result = timesheet.find([surname](Employee elem) {return elem.get_surname() == surname; });
			(result) ? cout << "\nЗапись с данной фамилией найдена!\n" : cout << "\nЗаписи с данной фамилией в контейнере нет!\n";
			break;
		}
		case 3:
		{
			cout << "\nВведите дату поступления на работу: ";
			Date date_of_admission = input_date();
			bool result = timesheet.find([date_of_admission](Employee elem) {return elem.get_date_of_admission() == date_of_admission; });
			(result) ? cout << "\nЗапись с данной датой поступления найдена!\n" : cout << "\nЗаписи с данной датой поступления в контейнере нет!\n";
			break;
		}
		case 4:
		{
			cout << "\nВведите оклад: ";
			double salary = input_double();
			bool result = timesheet.find([salary](Employee elem) {return elem.get_salary() == salary; });
			(result) ? cout << "\nЗапись с данным окладом найдена!\n" : cout << "\nЗаписи с данным окладом в контейнере нет!\n";
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}

void binary_find_menu(Timesheet<Employee>& timesheet)
{
	int choice;
	do
	{
		cout << "\nВыберите по какому параметру необходимо выполнить поиск: \n";
		cout << "[0] Выход в главное меню\n";
		cout << "[1] Номер отдела\n";
		cout << "[2] Фамилия\n";
		cout << "[3] Дата поступления\n";
		cout << "[4] Оклад\n";
		choice = input_info_in_range(0, 4);
		switch (choice)
		{
		case 1:
		{
			cout << "\nВведите номер отдела: ";
			int department_number = input_int();
			Employee pred;
			pred.set_department_number(department_number);
			bool result = timesheet.binary_find(Employee::compare_department_number, pred);
			(result) ? cout << "\nЗапись с данным номером отдела найдена!\n" : cout << "\nЗаписи с данным номером отдела в контейнере нет!\n";
			break;
		}
		case 2:
		{
			cout << "\nВведите фамилию: ";
			string surname;
			cin >> surname;
			Employee pred;
			pred.set_surname(surname);
			bool result = timesheet.binary_find(Employee::compare_surname, pred);
			(result) ? cout << "\nЗапись с данной фамилией найдена!\n" : cout << "\nЗаписи с данной фамилией в контейнере нет!\n";
			break;
		}
		case 3:
		{
			cout << "\nВведите дату поступления на работу: ";
			Date date_of_admission = input_date();
			Employee pred;
			pred.set_date_of_admission(date_of_admission);
			bool result = timesheet.binary_find(Employee::compare_date_of_admission, pred);
			(result) ? cout << "\nЗапись с данной датой поступления найдена!\n" : cout << "\nЗаписи с данной датой поступления в контейнере нет!\n";
			break;
		}
		case 4:
		{
			cout << "\nВведите оклад: ";
			double salary = input_double();
			Employee pred;
			pred.set_salary(salary);
			bool result = timesheet.binary_find(Employee::compare_salary, pred);
			(result) ? cout << "\nЗапись с данным окладом найдена!\n" : cout << "\nЗаписи с данным окладом в контейнере нет!\n";
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}

void note_print_menu(Timesheet<Employee>& timesheet)
{
	int choice;
	do
	{
		cout << "\nВыберите необходимое действие:\n";
		cout << "[0] Вернуться в прошлое меню\n";
		cout << "[1] Вывести выборку в консоль\n";
		cout << "[2] Вывести выборку в файл\n";
		choice = input_info_in_range(0, 2);
		switch (choice)
		{
		case 1:
		{
			cout << "\n";
			timesheet.print_notes_in_console();
			break;
		}
		case 2:
		{
			cout << "\nВведите имя файла: ";
			string file_name;
			cin >> file_name;
			ofstream f(file_name);
			timesheet.print(f);
			f.close();
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}

void find_set_menu(Timesheet<Employee>& timesheet)
{
	int choice;
	do
	{
		cout << "\nВыберите по какому параметру необходимо выполнить поиск: \n";
		cout << "[0] Выход в главное меню\n";
		cout << "[1] Номер отдела\n";
		cout << "[2] Фамилия\n";
		cout << "[3] Дата поступления\n";
		cout << "[4] Оклад\n";
		choice = input_info_in_range(0, 4);
		switch (choice)
		{
		case 1:
		{
			cout << "\nВведите номер отдела: ";
			int department_number = input_int();
			Timesheet<Employee> result = timesheet.find_set([department_number](Employee elem) { return elem.get_department_number() == department_number; });
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данным номером отдела в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		case 2:
		{
			cout << "\nВведите фамилию: ";
			string surname;
			cin >> surname;
			Timesheet<Employee> result = timesheet.find_set([surname](Employee elem) {return elem.get_surname() == surname; });
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данной датой поступления в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		case 3:
		{
			cout << "\nВведите дату поступления на работу: ";
			Date date_of_admission = input_date();
			Timesheet<Employee> result = timesheet.find_set([date_of_admission](Employee elem) {return elem.get_date_of_admission() == date_of_admission; });
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данной датой поступления в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		case 4:
		{
			cout << "\nВведите оклад: ";
			double salary = input_double();
			Timesheet<Employee> result = timesheet.find_set([salary](Employee elem) {return elem.get_salary() == salary; });
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данным окладом в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}

void binary_find_set_menu(Timesheet<Employee>& timesheet)
{
	int choice;
	do
	{
		cout << "\nВыберите по какому параметру необходимо выполнить поиск: \n";
		cout << "[0] Выход в главное меню\n";
		cout << "[1] Номер отдела\n";
		cout << "[2] Фамилия\n";
		cout << "[3] Дата поступления\n";
		cout << "[4] Оклад\n";
		choice = input_info_in_range(0, 4);
		switch (choice)
		{
		case 1:
		{
			cout << "\nВведите номер отдела: ";
			int department_number = input_int();
			Employee pred;
			pred.set_department_number(department_number);
			Timesheet<Employee> result = timesheet.binary_set_find(Employee::compare_department_number, pred);
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данным номером отдела в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		case 2:
		{
			cout << "\nВведите фамилию: ";
			string surname;
			cin >> surname;
			Employee pred;
			pred.set_surname(surname);
			Timesheet<Employee> result = timesheet.binary_set_find(Employee::compare_surname, pred);
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данной фамилией в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		case 3:
		{
			cout << "\nВведите дату поступления на работу: ";
			Date date_of_admission = input_date();
			Employee pred;
			pred.set_date_of_admission(date_of_admission);
			Timesheet<Employee> result = timesheet.binary_set_find(Employee::compare_date_of_admission, pred);
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данной датой поступления в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		case 4:
		{
			cout << "\nВведите оклад: ";
			double salary = input_double();
			Employee pred;
			pred.set_salary(salary);
			Timesheet<Employee> result = timesheet.binary_set_find(Employee::compare_salary, pred);
			note_print_menu(result);
			if (!result.get_size())
				cout << "\nЗаписи с данным окладом в контейнере нет!\n";
			else
			{
				cout << "\nНайденные записи:\n";
				result.print_notes_in_console();
			}
			break;
		}
		}
		cout << "\nДействие завершено\n";
	} while (choice != 0);
}