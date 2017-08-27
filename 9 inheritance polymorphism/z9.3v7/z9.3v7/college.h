#include "establishment.h"

class College : public Establishment
{
private:
	int spec;
public:
	College();
	College(string, int, int);
	College(College &);
	~College();
	void print_info() const;
	void set_spec();
	void get_spec() const;
};

College::College()
{}

College::College(string s, int n, int k) : Establishment(s, n), spec(k)
{}

College::College(College &u) : Establishment(u), spec(u.spec)
{}

College::~College()
{}

void College::set_spec()
{
	cout << "Введите количество специальностей: ";
	cin >> spec;
}

void College::get_spec() const
{
	cout << "Количество специальностей: " << spec << endl;
}

void College::print_info() const
{
	cout << "Информация о колледже" << endl;
	get_name();
	get_students();
	get_spec();
	cout << endl;
}