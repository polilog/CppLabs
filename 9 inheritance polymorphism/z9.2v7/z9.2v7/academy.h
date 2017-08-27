#include "establishment.h"

class Academy : public Establishment
{
private:
	bool mil;
public:
	Academy();
	Academy(string, int, bool);
	Academy(Academy &);
	~Academy();
	void print_info() const;
	void set_mil();
	void get_mil() const;
};

Academy::Academy()
{}

Academy::Academy(string s, int n, bool k) : Establishment(s, n), mil(k)
{}

Academy::Academy(Academy &u) : Establishment(u), mil(u.mil)
{}

Academy::~Academy()
{}

void Academy::set_mil()
{
	cout << "������� ������� �������: ";
	cin >> mil;
}

void Academy::get_mil() const
{
	cout << "������� ������� �������: ";
	if (mil)
		cout << "����" << endl;
	else
		cout << "���" << endl;
}

void Academy::print_info() const
{
	cout << "���������� �� ��������" << endl;
	get_name();
	get_students();
	get_mil();
	cout << endl;
}