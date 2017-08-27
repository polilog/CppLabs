// z7.1.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void get_memory(double **&, int);
void free_memory(double **&, int);
void multiply(double **, double **, double **&, int);
void sum(double **, double **, double **&, int);
void show_result(double **, int);
void input(double **&a, int n);

void get_memory(double *&, int);
void free_memory(double *&, int);
void multiply(double *, double *, double *&, int);
void sum (double *, double *, double *&, int);
void show_result(double *, int);
void input(double *&, int);

int _tmain(int argc, _TCHAR* argv[])
{
	
	int n;
	cout << "n = ";
	cin >> n;
	srand(time(NULL));

	// Первый способ
	double *A, *B;
	get_memory(A, n);
	get_memory(B, n);
	input(A, n);
	input(B, n);
	if(!A || !B)
		return 1;

	double *AB, *BA;
	get_memory(AB, n);
	get_memory(BA, n);
	if (!AB || !BA)
		return 1;

	multiply(A, B, AB, n);
	multiply(B, A, BA, n);
	free_memory(A, n);
	free_memory(B, n);

	double *C;
	get_memory(C, n);
	if (!C)
		return 1;
	sum (AB, BA, C, n);
	show_result(C, n);
	free_memory(AB, n);
	free_memory(BA, n);
	free_memory(C, n);

	//Второй способ
	double **a, **b;
	get_memory(a, n);
	get_memory(b, n);
	if (!a || !b)
		return 1;
	input(a, n);
	input(b, n);


	double **ab, **ba;
	get_memory(ab, n);
	get_memory(ba, n);
	if (!ab || !ba)
		return 1;

	multiply(a, b, ab, n);
	multiply(b, a, ba, n);
	free_memory(a, n);
	free_memory(b, n);

	double **c;
	get_memory(c, n);
	if (!c)
		return 1;
	sum(ab, ba, c, n);
	show_result(c, n);
	free_memory(ab, n);
	free_memory(ba, n);
	free_memory(c, n);

	return 0;
}

void get_memory(double **&a, int n)
{
	a = new double* [n];
	for (int i = 0; i < n; i++)
		a[i] = new double [n];
}

void free_memory(double **&a, int n)
{
	for (int i = 0; i < n; i++)
		delete [] a[i];
	delete [] a;
}

void multiply(double **a, double **b, double **&ab, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ab[i][j] = 0;
			for (int k = 0; k < n; k++)
				ab[i][j] += a[i][k] * b[k][j];
		}
}

void sum(double **a, double **b, double **&c, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void show_result(double **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void input(double **&a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand () % 31;
			cout << setw(4) << a[i][j] << " ";
		}
	cout << endl;
	}
	cout << endl;
}


void get_memory(double *&a, int n)
{
	a = new double [n * n];
}

void free_memory(double *&a, int n)
{
	delete [] a;
}

void multiply(double *a, double *b, double *&ab, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ab[n * i + j] = 0;
			for (int k = 0; k < n; k++)
				ab[n * i + j] += a[n * i + k] * b[n * k + j];
		}
}

void sum(double *a, double *b, double *&c, int n)
{
	for (int i = 0; i < n * n; i++)
		c[i] = a[i] + b[i];
}

void input(double *&a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[n * i + j] = rand () % 31;
			cout << setw(4) << a[n * i + j] << " ";
		}
	cout << endl;
	}
	cout << endl;
}

void show_result(double *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[n * i + j] << " ";
		cout << endl;
	}
	cout << endl;
}