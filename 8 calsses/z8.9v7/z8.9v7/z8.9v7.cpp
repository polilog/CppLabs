// z8.9v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <ctime>
#include <list>
#include <algorithm>

using namespace std;

void create_list(list <int> &);
void print(list <int> &);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	list <int> list1, list2;
	create_list(list1);
	create_list(list2);
	cout << endl;

	list1.sort();
	list2.sort();

	list <int> difference(list1.size() + list2.size());
	list <int>::iterator last = set_symmetric_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), difference.begin());
	difference.erase(last, difference.end());

	print(list1);
	print(list2);
	print(difference);
	return 0;
}

void create_list(list <int> &lst)
{
	cout << "Введите количество элементов: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 30;
		cout << x << " ";
		lst.push_back(x);
	}
	cout << endl;
}

void print(list <int> &lst)
{
	list <int>::iterator p = lst.begin();
	while (p != lst.end())
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}
