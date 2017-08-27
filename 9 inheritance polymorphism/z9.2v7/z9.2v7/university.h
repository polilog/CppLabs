#include "establishment.h"

class University : public Establishment
{
private:
	int fac;
public:
	University();
	University(string, int, int);
	University(University &);
	~University();
	void print_info() const;
	void set_fac();
	void get_fac() const;
};

University::University()
{}

University::University(string s, int n, int k) : Establishment(s, n), fac(k)
{}

University::University(University &u) : Establishment(u), fac(u.fac)
{}

University::~University()
{}

void University::set_fac()
{
	cout << "Введите количество факультетов: ";
	cin >> fac;
}

void University::get_fac() const
{
	cout << "Количество факультетов: " << fac <<endl;
}

void University::print_info() const
{
	cout << "Информация об университете" << endl;
	get_name();
	get_students();
	get_fac();
	cout << endl;
}