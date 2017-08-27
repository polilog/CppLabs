// z5.1.2.2t.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX = 100;

template <class T>
void get_arr(T [MAX][MAX], T [MAX][MAX], int);

template <class T>
void find_max(T [][MAX], T [][MAX], int);

template <class T>
void print(T **, int);

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "n = ";
	cin >> n;
	int A[MAX][MAX], B[MAX][MAX];
	get_arr(A, B, n);
	find_max(A, B, n);
	//вспомогательный массив указателей на строки матрицы, имя которого - указатель на массив указателей
	int *p[MAX];
	for (int i = 0; i < n; i++)
		p[i] = &B[i][0];
	print(p, n);

	return 0;
}

template <class T>
void get_arr(T A[MAX][MAX], T B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 0;
		}
}

template <class T>
void find_max(T A[][MAX], T B[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			T max  = A[i][j];
			for (int k = i; k < n; k++)
					for (int l = j; l < n; l++)
							if (max < A[k][l])
								max = A[k][l];
			B[i][j] = max;
		}
}

template <class T>
void print(T **B, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
}