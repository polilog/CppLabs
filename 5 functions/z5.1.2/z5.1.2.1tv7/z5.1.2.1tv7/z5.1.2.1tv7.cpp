// z5.1.2.1tv7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;
//3.1
template <class T>
int vvod_s_klav (T a[]);

template <class T>
int vvod_sluch(T a[]);

template <class T>
void vyvod(T a[], int n);

template <class T>
void result(T a[], T b[], int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n, a[100], b[100];

	n = vvod_s_klav(a);
	result(a, b, n);
	vyvod(b, n);

	n = vvod_sluch(a);
	result(a, b, n);
	vyvod (b, n);
	
	return 0;
}

template <class T>
int vvod_s_klav (T a[])
{
	int n;
	setlocale (LC_ALL, "rus");
	cout << "n = ";
	cin >> n;
	cout << "Введите последовательность:" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	return n;
}

template <class T>
int vvod_sluch(T a[])
{
	int n;
	setlocale (LC_ALL, "rus");
	cout << "n = ";
	cin >> n;
	cout << "Случайная последовательность:" << endl;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	return n;
}

template <class T>
void vyvod(T a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

template <class T>
void result(T a[], T b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				b[i]++;
}