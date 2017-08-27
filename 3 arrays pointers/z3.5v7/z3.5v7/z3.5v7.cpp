// z3.5v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int m, n;
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	double A[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	cout << endl;

	double sum[100];
	for (int i = 0; i < n; i++)
		sum[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum[i] += A[i][j];

	double temp;
	for (int i = 1; i < n; i++)
		for (int j = n - 1; j >= i; j--)
			if (sum[j - 1] > sum[j])
			{
				temp = sum[j - 1];
				sum[j - 1] = sum[j];
				sum[j] = temp;
				for (int k = 0; k < m; k++)
				{
					temp = A[j - 1][k];
					A[j - 1][k] = A[j][k];
					A[j][k] = temp;
				}
			}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}

