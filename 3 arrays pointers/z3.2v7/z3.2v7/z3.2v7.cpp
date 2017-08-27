// z3.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int A[100][100], B[100][100], n;
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
			B[i][j] = 0;
		}
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

