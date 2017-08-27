// z3.6v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	srand (time(NULL));
	int A[100][100], n;
	cout << "n = ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			 A[i][j] = rand()%100;
			 cout <<setw(3)<< A[i][j] << " " ;
		}
		cout << endl;
	}

	cout <<endl<<endl;

	int B[100][100];
	int max = A[0][0];
	for (int k = 0; k < n; k++)
	{
		for (int l = 0; l <= k; l++)
			if (A[k - l][l] > max)
				max = A[k - l][l];
		for (int l = 0; l <= k; l++)
			B[k - l][l] = max;
	}

	for (int k = 1; k < n; k++)
	{
		for (int l = 0; l < n - k; l++)
			if (A[k + l][n - 1 - l] > max)
				max = A[k  + l][n - 1 - l];
		for (int l = 0; l < n - k; l++)
			B[k  + l][n - 1 - l] = max;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout <<setw(3)<< B[i][j] << " ";
		cout << endl;
	}
	return 0;
}

