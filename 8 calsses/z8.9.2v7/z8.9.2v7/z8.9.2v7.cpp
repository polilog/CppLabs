// z8.9.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#include <ctime>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
void create_list(list <T> &, int);

template <class T>
void print_list(list <T> &);

template <class T>
T count(list <T> &);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	list <int> lst;
	int n;
	cout << "n = ";
	cin >> n;
	create_list(lst, n);
	print_list(lst);
	int result = count(lst);
	cout << "result = " << result << endl;
	return 0;
}

template <class T>
void create_list(list <T> &lst, int n)
{
	cout << "Введите элементы списка:" << endl;
	T x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		lst.push_back(x);
	}
}

template <class T>
void print_list(list <T> &lst)
{
	cout << "Ваш список:" << endl;
	list <T>::iterator i;
	for (i = lst.begin(); i != lst.end(); i++)
		cout << *i << " ";
	cout << endl;
}

template <class T>
T count(list <T> &lst)
{
	T result = 0;
	list <T>::iterator first = lst.begin();
	list <T>::reverse_iterator last = lst.rbegin();
	int size = lst.size();
	if (size % 2 == 0)
	{
		for (int i = 0; i < size / 2; i++)
		{
			result += (*first) * (*last);
			first++;
			last++;
		}
		return result;
	}
	else
	{
		cout << "В списке дожно быть четное число элементов";
		return 0;
	}
}

