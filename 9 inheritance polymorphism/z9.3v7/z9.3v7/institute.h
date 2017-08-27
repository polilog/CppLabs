#include "establishment.h"

class Institute : public Establishment
{
private:
	int stuff;
public:
	Institute();
	Institute(string, int, int);
	Institute(Institute &);
	~Institute();
	void print_info() const;
	void set_stuff();
	void get_stuff() const;
};

Institute::Institute()
{}

Institute::Institute(string s, int n, int k) : Establishment(s, n), stuff(k)
{}

Institute::Institute(Institute &u) : Establishment(u), stuff(u.stuff)
{}

Institute::~Institute()
{}

void Institute::set_stuff()
{
	cout << "Введите количество сотрудников: ";
	cin >> stuff;
}

void Institute::get_stuff() const
{
	cout << "Количество сотрудников: " << stuff << endl;
}

void Institute::print_info() const
{
	cout << "Информация об институте" << endl;
	get_name();
	get_students();
	get_stuff();
	cout << endl;
}