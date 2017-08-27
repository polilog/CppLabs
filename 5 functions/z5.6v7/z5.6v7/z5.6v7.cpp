// z5.6v7.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <clocale>
#include "functions.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	int n, a[100];
	cout << "Введите n = ";
	cin >> n;
	cout << endl;

	cout << "Сортировка выбором" << endl << endl;

	asc_ord (n, a);
	s_sort (n, a);
	cout << endl;

	des_ord (n, a);
	s_sort (n, a);
	cout << endl;

	rand_ord (n, a);
	s_sort (n, a);
	cout << endl;

	cout << "Быстрая сортировка" << endl << endl;

	int comp = 0, swap = 0;
	asc_ord (n, a);
	q_sort (0, n - 1, a, comp, swap);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << comp << endl;
	cout << "Перемещения: " << swap << endl << endl;

	comp = 0, swap = 0;
	des_ord (n, a);
	q_sort (0, n - 1, a, comp, swap);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << comp << endl;
	cout << "Перемещения: " << swap << endl << endl;

	comp = 0, swap = 0;
	rand_ord (n, a);
	q_sort (0, n - 1, a, comp, swap);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << comp << endl;
	cout << "Перемещения: " << swap << endl << endl;
	return 0;
}



