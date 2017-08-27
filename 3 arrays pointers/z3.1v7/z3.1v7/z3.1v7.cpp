// z3.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	srand (time (NULL));
	int A[100], B[100], n, i, j;
	cout << "n = ";
	cin >> n;
	cout << "Введите последовательность:" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
		B[i] = 0;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			if (A[i] < A[j])
				B[i]++;
	for (i = 0; i < n; i++)
		cout << B[i] << " ";
	cout << endl;

	cout << "Случайная последовательность:" << endl;
	for (i = 0 ; i < n; i++)
	{
		A[i] =  rand() % 100;
		cout << A[i] << " ";
		B[i] = 0;
	}
	cout << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			if (A[i] < A[j])
				B[i]++;
	for (i = 0; i < n; i++)
		cout << B[i] << " ";
	cout << endl;

	cout << "Инициализированный массив:" << endl;
	int C[10] = {1, 6, 3, 7, 5, 9, 12, 15, 7, 11};
	for (i = 0 ; i < 10; i++)
	{
		cout << C[i] << " ";
		B[i] = 0;
	}
	cout << endl;
	for (i = 0; i < 10; i++)
		for (j = 0; j < i; j++)
			if (C[i] < C[j])
				B[i]++;
	for (i = 0; i < 10; i++)
		cout << B[i] << " ";
	cout << endl;
	return 0;
}

