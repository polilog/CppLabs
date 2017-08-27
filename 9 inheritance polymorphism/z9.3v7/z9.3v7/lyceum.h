#include "establishment.h"

class Lyceum : public Establishment
{
private:
	int term;
public:
	Lyceum();
	Lyceum(string, int, int);
	Lyceum(Lyceum &);
	~Lyceum();
	void print_info() const;
	void set_term();
	void get_term() const;
};

Lyceum::Lyceum()
{}

Lyceum::Lyceum(string s, int n, int k) : Establishment(s, n), term(k)
{}

Lyceum::Lyceum(Lyceum &u) : Establishment(u), term(u.term)
{}

Lyceum::~Lyceum()
{}

void Lyceum::set_term()
{
	cout << "Введите количество сотрудников: ";
	cin >> term;
}

void Lyceum::get_term() const
{
	cout << "Срок обучения: " << term <<endl;
}

void Lyceum::print_info() const
{
	cout << "Информация о лицее" << endl;
	get_name();
	get_students();
	get_term();
	cout << endl;
}