// z3.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int n, A[100][100];
	cout << "n = ";
	cin >> n;

	int i0, j0;
	if (n % 2 == 1)
	{
		i0 = n / 2;
		j0 = n / 2;
	}
	else
	{
		i0 = n / 2 - 1;
		j0 = n / 2 ;
	}
	cin >> A[i0][j0];

	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> A[i0][j0 - j];
			}
			for (int j = 1; j <= i; j++)
			{
				cin >> A[i0 + j][j0 - i];
			}
			j0 -= i;
			i0 += i;
		}
		if (i % 2 == 0)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> A[i0][j0 + j];
			}
			for (int j = 1; j <= i; j++)
			{
				cin >> A[i0 - j][j0 + i];
			}
			j0 += i;
			i0 -= i;
		}
	}

	if (i0 == 0)
	{
		for (int i = n - 2; i >= 0; i--)
			cin >> A[0][i];
	}
	if (i0 == n-1)
	{
		for (int i = 1; i < n ; i++)
			cin >> A[n-1][i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw (3) << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}