// z5.7v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <clocale>
#include <string>

using namespace std;

template <class T>
void merge (T a[], int lb, int split, int ub, int &sravn, int &perem)
{
	int pos1 = lb;
	int pos2 = split + 1;
	int pos3 = 0;
	T *temp = new T[ub - lb + 1];
	while (pos1 <= split && pos2 <= ub)
	{
		sravn++;
		perem++;
		if (a[pos1] < a[pos2])
			temp[pos3++] = a[pos1++];
		else
			temp[pos3++] = a[pos2++];
	}
	while (pos2 <= ub)
	{
		perem++;
		temp[pos3++] = a[pos2++];
	}
	while (pos1 <= split)
	{
		perem++;
		temp[pos3++] = a[pos1++];
	}
	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
		a[lb + pos3] = temp[pos3];
	delete [] temp;
}

template <class T>
void merge_sort (T a[], int lb, int ub, int &sravn, int &perem)
{
	int split;
	if (lb < ub)
	{
		split = (lb + ub) / 2;
		merge_sort(a, lb, split, sravn, perem);
		merge_sort(a, split + 1, ub, sravn, perem);
		merge(a, lb, split, ub, sravn, perem);
	}
}

template <class T>
void asc_ord (int n, T a[])
{
	srand (time (NULL));
	a[0] = rand () % 21 - 10;
	cout << a[0] << " ";
	for (int i = 1; i < n; i ++)
	{
		a[i] = a[i-1] + rand () % 6;
		cout << a[i] << " ";
	}
	cout << endl;
}

template <class T>
void des_ord (int n, T a[])
{
	srand (time (NULL));
	a[0] = rand () % 21;
	cout << a[0] << " ";
	for (int i = 1; i < n; i ++)
	{
		a[i] = a[i-1] - rand () % 6;
		cout << a[i] << " ";
	}
	cout << endl;
}

template <class T>
void rand_ord (int n, T a[])
{
	srand (time (NULL));
	for (int i = 0; i < n; i ++)
	{
		a[i] = rand () % 26 - 5;
		cout << a[i] << " ";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, a[100];
	setlocale(LC_ALL, "rus");
	cout << "n = ";
	cin >> n;

	int sravn = 0, perem = 0;
	asc_ord(n, a);
	merge_sort(a, 0, n - 1, sravn, perem);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << sravn << endl;
	cout << "Пермещения: " << perem << endl;

	sravn = 0, perem = 0;
	des_ord(n, a);
	merge_sort(a, 0, n - 1, sravn, perem);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << sravn << endl;
	cout << "Пермещения: " << perem << endl;

	sravn = 0, perem = 0;
	rand_ord(n, a);
	merge_sort(a, 0, n - 1, sravn, perem);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << sravn << endl;
	cout << "Пермещения: " << perem << endl;

	sravn = 0, perem = 0;
	string str[100];
	cout << "n = ";
	cin >> n;
	cout << "Введите строки" << endl;
	for (int i = 0; i < n + 1; i++)
		getline (cin, str[i]);
	
	merge_sort(str, 1, n, sravn, perem);
	for (int i = 1; i <= n; i++)
		cout << str[i] << " ";
	cout << endl;
	cout << "Сравнения: " << sravn << endl;
	cout << "Пермещения: " << perem << endl;
	return 0;
}

