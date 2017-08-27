// z7.2v7.cpp: определяет точку входа для консольного приложения.
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
struct list
{
	student st;
	list* next;
};

void read_file(ifstream &, student &);
void add(list *&, student &);
void create_list(list *&, ifstream &);
void find_gt(list *, char [], list *&, list *&);
void find_eq();
void show(list *);
void find_st(list *&, int, list *&);
void delete_list(list *&);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	ifstream fin("f.txt");
	if (!fin)
	{
		cout << "File error" << endl;
		return 1;
	}

	list* top = NULL;
	create_list(top, fin);
	fin.close();
	show(top);

	list *result = NULL;
	int n;
	cout << "n = ";
	cin >> n;
	find_st(top, n, result);
	cout << "Отличники" << endl;
	show(result);
	cout << "Остальные" << endl;
	show(top);

	delete_list(top);
	delete_list(result);

	return 0;
}

void read_file(ifstream &fin, student &st)
{	
	fin >> st.st_name.surname >> st.st_name.praenomen >> st.st_name.patronymic
				>> st.age >> st.sex >> st.course >> st.progress;
}

void add(list *&top, student &st)
{
	list *nv, *pv = NULL, *ppv = NULL;
	nv = new list;
	nv->st = st;
	nv->next = NULL;
	if (!top)
		top = nv;
	else
	{
		if (strcmp(top->st.st_name.surname, st.st_name.surname) >= 0) 
		{
			nv->next = top;
			top = nv;
		}
		else
		{
			find_gt(top, st.st_name.surname, pv, ppv);
			nv->next = pv;
			ppv->next = nv;
		}
	}
}

void create_list (list *&top, ifstream &fin)
{
	student st;
	while (!fin.eof())
	{
		read_file(fin, st);
		add(top, st);
	}
}

void find_gt(list *top, char key[], list *&pv, list *&ppv)
{
	pv = top;
	ppv = top;
	while (pv && strcmp(pv->st.st_name.surname, key) <= 0) 
	{
		ppv = pv;
		pv = pv->next;
	}
}

void show(list *top)
{
	while (top)
	{
		cout << top->st.st_name.surname << " " << top->st.st_name.praenomen << " " << top->st.st_name.patronymic
				<< " " << top->st.age << " " << top-> st.sex << " " << top->st.course << " " << top->st.progress << " " << endl;
		top = top->next;
	}
	cout << endl;
}

void find_st(list *&top, int n, list *&result)
{
	list *ppv = NULL, *pv = top;
	while (pv)
	{
		if (pv->st.course == n && pv->st.progress >= 8)
		{
			add(result, pv->st);
			if (ppv)
				ppv->next = pv->next;
			else
				top = top->next;
		}
		else
			ppv = pv;
		pv = pv->next;
	}
}

void delete_list(list *&top)
{
	list *pv = NULL;
	while (top)
	{
		pv = top;
		top = top->next;
		delete pv;
	}
	pv = NULL;
}
