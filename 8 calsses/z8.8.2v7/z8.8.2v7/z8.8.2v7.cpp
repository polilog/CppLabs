// z8.8.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void create_matrix(vector <vector <T>> &, int);

template <class T>
void print_matrix(vector <vector <T>> &, int);

template <class T>
void multiply(vector <vector <T>> &,vector <vector <T>> &, vector <vector <T>> &, int);

template <class T>
void sum(vector <vector <T>> &,vector <vector <T>> &, vector <vector <T>> &, int);


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "n = ";
	cin >> n;

	vector <vector <int>> a, b;
	create_matrix(a, n);
	create_matrix(b, n);
	print_matrix(a, n);
	print_matrix(b, n);
	
	vector <vector <int>> ab, ba, c;
	multiply(a, b, ab, n);
	multiply(b, a, ba, n);
	sum(ab, ba, c, n);

	print_matrix(ab, n);
	print_matrix(ba, n);
	print_matrix(c, n);

	return 0;
}

template <class T>
void create_matrix(vector <vector <T>> &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector <int> temp;
		for (int j = 0; j < n; j++)
		{
			int x = rand() % 20;
			temp.push_back(x);
		}
		a.push_back(temp);
	}
}

template <class T>
void print_matrix(vector <vector <T>> &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

template <class T>
void multiply(vector <vector <T>> &a, vector <vector <T>> &b, vector <vector <T>> &ab, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector <int> temp;
		for (int j = 0; j <n; j++)
		{
			int x = 0;
			for (int k = 0; k < n; k++)
				x += a[i][k] * b[k][j];
			temp.push_back(x);
		}
		ab.push_back(temp);
	}
}

template <class T>
void sum(vector <vector <T>> &a, vector <vector <T>> &b, vector <vector <T>> &c, int n)
{
	for (int i = 0; i < n; i++)
	{
		vector <int> temp;
		for (int j = 0; j < n; j++)
			temp.push_back(a[i][j] + b[i][j]);
		c.push_back(temp);
	}
}