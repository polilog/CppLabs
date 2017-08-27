// z6.2.1v7.cpp: определ€ет точку входа дл€ консольного приложени€.
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

void read_file(ifstream &, ofstream &, student &, short &);

void find_student(student &, ofstream &, short &);

void show_students(ifstream &, student &);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	do{
		ifstream fin("f.txt");
		if (!fin)
		{
			cout << "File error" << endl;
			//return 1;
			break;
		}

		ifstream gin("g.txt");
		if (!gin)
		{
			cout << "File error" << endl;
			return 1;
		}

		ofstream gout("g.txt");
		if (!gout)
		{
			cout << "File error" << endl;
			return 1;
		}

		student st;
		short n;
		cout << "¬ведите курс: ";
		cin >> n;
		read_file(fin, gout, st, n);
		show_students(gin, st);
	
	}while(false);



	
	return 0;
}

void read_file(ifstream &fin, ofstream &gout, student &st, short &n)
{	
	while (!fin.eof())
	{
		fin >> st.st_name.praenomen >> st.st_name.patronymic >> st.st_name.surname
				>> st.age >> st.sex >> st.course >> st.progress;
			find_student(st, gout, n);
	}
	fin.close();
	gout.close();
}

void find_student(student &st, ofstream &gout, short &n)
{
	if (st.progress >= 8 && st.course == n)
	{
		gout << st.st_name.praenomen << " " << st.st_name.patronymic << " " << st.st_name.surname
			<< " " << st.age << " " << st.sex << " " << st.course << " " << st.progress << endl;
	}
}

void show_students(ifstream &fin, student &st)
{
	while (!fin.eof())
	{
		fin >> st.st_name.praenomen >> st.st_name.patronymic >> st.st_name.surname
				>> st.age >> st.sex >> st.course >> st.progress;
		if(!fin.eof())
		cout << st.st_name.praenomen << " " << st.st_name.patronymic << " " << st.st_name.surname
				<< " " << st.age << " " << st.sex << " " << st.course << " " << st.progress << endl;
	}
	fin.close();
}

