#ifndef ESTABLISHMENT_H
#define ESTABLISHMENT_H

#include <iostream>
#include <clocale>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Establishment
{
protected:
	string name;
	int number_of_students;
public:
	Establishment();
	Establishment(string &, int);
	Establishment(Establishment &);
	~Establishment();
	void set_name();
	void get_name() const;
	void set_students();
	void add_student();
	void get_students() const;
	virtual void print_info() const = 0;
};

Establishment::Establishment() : number_of_students(0), name ("N/A")
{}

Establishment::Establishment(string &temp, int n)
{
	name = temp;
	number_of_students = n;
}

Establishment::Establishment(Establishment &t)
{
	name = t.name;
	number_of_students = t.number_of_students;
}

Establishment::~Establishment()
{}

void Establishment::set_name()
{
	cout << "Введите название: ";
	string temp;
	getline(cin, temp);
	name = temp;
}

void Establishment::get_name() const
{
	cout << "Название: " <<  name << endl;
}

void Establishment::set_students()
{
	int n;
	cin >> n;
	cout << "Введите количество учащихся: ";
	number_of_students = n;
}

void Establishment::add_student()
{
	number_of_students++;
}

void Establishment::get_students() const
{
	cout << "Количество учащихся: " << number_of_students << endl;
}

#endif //ESTABLISHMENT_H	