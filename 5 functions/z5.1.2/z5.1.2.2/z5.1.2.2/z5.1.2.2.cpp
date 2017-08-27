// z5.1.2.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX = 100;


void get_arr(char [MAX][MAX], char [MAX][MAX], int);
void get_arr(int [MAX][MAX], int [MAX][MAX], int);
void get_arr(float [MAX][MAX], float [MAX][MAX], int);
void get_arr(double [MAX][MAX], double [MAX][MAX], int);

void find_max(char [][MAX], char [][MAX], int);
void find_max(int [][MAX], int [][MAX], int);
void find_max(float [][MAX], float [][MAX], int);
void find_max(double [][MAX], double [][MAX], int);

void print(char **, int);
void print(int **, int);
void print(float **, int);
void print(double **, int);


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


void get_arr(char A[MAX][MAX], char B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 0;
		}
}
void get_arr(int A[MAX][MAX], int B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 0;
		}
}
void get_arr(float A[MAX][MAX], float B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 0;
		}
}
void get_arr(double A[MAX][MAX], double B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 0;
		}
}

void find_max(char A[][MAX], char B[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char max  = A[i][j];
			for (int k = i; k < n; k++)
					for (int l = j; l < n; l++)
							if (max < A[k][l])
								max = A[k][l];
			B[i][j] = max;
		}
}
void find_max(int A[][MAX], int B[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int max  = A[i][j];
			for (int k = i; k < n; k++)
					for (int l = j; l < n; l++)
							if (max < A[k][l])
								max = A[k][l];
			B[i][j] = max;
		}
}
void find_max(float A[][MAX], float B[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			float max  = A[i][j];
			for (int k = i; k < n; k++)
					for (int l = j; l < n; l++)
							if (max < A[k][l])
								max = A[k][l];
			B[i][j] = max;
		}
}
void find_max(double A[][MAX], double B[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			double max  = A[i][j];
			for (int k = i; k < n; k++)
					for (int l = j; l < n; l++)
							if (max < A[k][l])
								max = A[k][l];
			B[i][j] = max;
		}
}

void print(char **B, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
}
void print(int **B, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
}
void print(float **B, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
}
void print(double **B, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
}
