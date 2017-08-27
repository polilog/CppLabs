// z5.1.2.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

//3.1
int vvod_s_klav (int a[]);
int vvod_s_klav (char a[]);
int vvod_s_klav (float a[]);
int vvod_s_klav (double a[]);

int vvod_sluch(int a[]);
int vvod_sluch(char a[]);
int vvod_sluch(float a[]);
int vvod_sluch(double a[]);

void vyvod(int a[], int n);
void vyvod(char a[], int n);
void vyvod(float a[], int n);
void vyvod(double a[], int n);

void result(int a[], int b[], int n);
void result(char a[], char b[], int n);
void result(float a[], float b[], int n);
void result(double a[], double b[], int n);

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


int vvod_s_klav(int a[])
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

int vvod_s_klav(char a[])
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

int vvod_s_klav(float a[])
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

int vvod_s_klav(double a[])
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


int vvod_sluch(int a[])
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

int vvod_sluch(float a[])
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

int vvod_sluch(char a[])
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

int vvod_sluch(double a[])
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


void vyvod(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

void vyvod(char a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

void vyvod(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

void vyvod(double a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}


void result(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				b[i]++;
}

void result(char a[], char b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				b[i]++;
}

void result(float a[], float b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				b[i]++;
}

void result(double a[], double b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				b[i]++;
}