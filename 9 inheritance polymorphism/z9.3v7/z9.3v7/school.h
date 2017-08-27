#include "establishment.h"

class School : public Establishment
{
private:
	string adress;
public:
	School();
	School(string, int, string);
	School(School &);
	~School();
	void print_info() const;
	void set_adress();
	void get_adress() const;
};

School::School()
{}

School::School(string s, int n, string k) : Establishment(s, n), adress(k)
{}

School::School(School &u) : Establishment(u), adress(u.adress)
{}

School::~School()
{}

void School::set_adress()
{
	cout << "Введите срок обучения: ";
	getline(cin, adress);
}

void School::get_adress() const
{
	cout << "Срок обучения: " << adress << endl;
}

void School::print_info() const
{
	cout << "Информация о школе" << endl;
	get_name();
	get_students();
	get_adress();
	cout << endl;
}