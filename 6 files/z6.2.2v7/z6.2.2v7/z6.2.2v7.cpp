// z6.2.2v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <clocale>

using namespace std;

struct name
{
	char praenomen[30];
	char patronymic[30];
	char surname[30];
};
struct student
{
	name st_name;
	short age;
	bool sex;
	short course;
	float progress;
};

void create_file(ifstream &, ofstream &);

void read_file(ifstream &, ofstream &, short &);

void find_student(student &, ofstream &, short &);

void show_students(ifstream &);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	ifstream fin("f.txt");
	if (!fin)
	{
		cout << "File error" << endl;
		return 1;
	}

	ofstream fout("f.bin", ios::binary);
	if (!fout)
	{
		cout << "File error" << endl;
		return 1;
	}

	create_file(fin, fout);
	fin.close();
	fout.close();

	ifstream fin1("f.bin", ios::binary);
	if (!fin1)
	{
		cout << "File error" << endl;
		return 1;
	}

	ofstream gout("g.bin", ios::binary);
	if (!gout)
	{
		cout << "File error" << endl;
		return 1;
	}

	short n;
	cout << "¬ведите курс: ";
	cin >> n;
	read_file(fin1, gout, n);
	fin1.close();
	gout.close();

	ifstream gin("g.bin", ios::binary);
	if (!gin)
	{
		cout << "File error" << endl;
		return 1;
	}
	show_students(gin);
	gin.close();

	return 0;
}

void create_file(ifstream &fin, ofstream &gout)
{
	student st;
	while (!fin.eof())
	{
		fin >> st.st_name.praenomen >> st.st_name.patronymic >> st.st_name.surname
				>> st.age >> st.sex >> st.course >> st.progress;
		gout.write(reinterpret_cast <char*>(&st.st_name.praenomen), 30 * sizeof (char));
		gout.write(reinterpret_cast <char*>(&st.st_name.patronymic), 30 * sizeof (char));
		gout.write(reinterpret_cast <char*>(&st.st_name.surname), 30 * sizeof (char));
		gout.write(reinterpret_cast <char*>(&st.age), sizeof (short));
		gout.write(reinterpret_cast <char*>(&st.sex), sizeof (bool));
		gout.write(reinterpret_cast <char*>(&st.course), sizeof (short));
		gout.write(reinterpret_cast <char*>(&st.progress), sizeof (float));
	}
}

void read_file(ifstream &fin, ofstream &gout, short &n)
{	
	student st;
	while (!fin.eof())
	{
		fin.read(reinterpret_cast <char*>(&st.st_name.praenomen), 30 * sizeof (char));
		fin.read(reinterpret_cast <char*>(&st.st_name.patronymic), 30 * sizeof (char));
		fin.read(reinterpret_cast <char*>(&st.st_name.surname), 30 * sizeof (char));
		fin.read(reinterpret_cast <char*>(&st.age), sizeof (short));
		fin.read(reinterpret_cast <char*>(&st.sex), sizeof (bool));
		fin.read(reinterpret_cast <char*>(&st.course), sizeof (short));
		fin.read(reinterpret_cast <char*>(&st.progress), sizeof (float));
		find_student(st, gout, n);
	}
}

void find_student(student &st, ofstream &gout, short &n)
{
	if (st.progress >= 8 && st.course == n)
	{
		gout.write(reinterpret_cast <char*>(&st.st_name.praenomen), 30 * sizeof (char));
		gout.write(reinterpret_cast <char*>(&st.st_name.patronymic), 30 * sizeof (char));
		gout.write(reinterpret_cast <char*>(&st.st_name.surname), 30 * sizeof (char));
		gout.write(reinterpret_cast <char*>(&st.age), sizeof (short));
		gout.write(reinterpret_cast <char*>(&st.sex), sizeof (bool));
		gout.write(reinterpret_cast <char*>(&st.course), sizeof (short));
		gout.write(reinterpret_cast <char*>(&st.progress), sizeof (float));
	}
}

void show_students(ifstream &fin)
{
	student st;
	fin.read(reinterpret_cast <char*>(&st.st_name.praenomen), 30 * sizeof (char));
	fin.read(reinterpret_cast <char*>(&st.st_name.patronymic), 30 * sizeof (char));
	fin.read(reinterpret_cast <char*>(&st.st_name.surname), 30 * sizeof (char));
	fin.read(reinterpret_cast <char*>(&st.age), sizeof (short));
	fin.read(reinterpret_cast <char*>(&st.sex), sizeof (bool));
	fin.read(reinterpret_cast <char*>(&st.course), sizeof (short));
	fin.read(reinterpret_cast <char*>(&st.progress), sizeof (float));
	while (!fin.eof())
	{
		cout << st.st_name.praenomen << " " << st.st_name.patronymic << " " << st.st_name.surname
				<< " " << st.age << " " << st.sex << " " << st.course << " " << st.progress << endl;
		fin.read(reinterpret_cast <char*>(&st.st_name.praenomen), 30 * sizeof (char));
		fin.read(reinterpret_cast <char*>(&st.st_name.patronymic), 30 * sizeof (char));
		fin.read(reinterpret_cast <char*>(&st.st_name.surname), 30 * sizeof (char));
		fin.read(reinterpret_cast <char*>(&st.age), sizeof (short));
		fin.read(reinterpret_cast <char*>(&st.sex), sizeof (bool));
		fin.read(reinterpret_cast <char*>(&st.course), sizeof (short));
		fin.read(reinterpret_cast <char*>(&st.progress), sizeof (float));
	}
}

