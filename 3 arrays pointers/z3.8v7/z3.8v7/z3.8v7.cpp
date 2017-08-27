// z3.8v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	
	int n;
	cout << "¬ведите ранг матрицы n = ";
	cin >> n;

	const int max = 100;
	double A[max], B[max];
	cout << "¬ведите матрицу A" << endl;
	for (int i = 0; i < (n * (n + 1)) / 2; i++)
		cin >> A[i];
	cout << "¬ведите матрицу B" << endl;
	for (int i = 0; i < (n * (n + 1)) / 2; i++)
		cin >> B[i];

	double C[max][max];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			C[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				int n1 = ((2 * n - i + 1) * i) / 2 + k - i;
				int n2 = ((2 * n - k + 1) * k) / 2 + j - k;
				C[i][j] += (A[n1] * B[n2]);
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			double temp = C[i][j];
			C[i][j] = C[j][i];
			C[j][i] = temp;
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw (4) <<  C[i][j];
		cout << endl;
	}
	return 0;
}

