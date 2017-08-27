// z2.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int m, n;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	int i = 1, j, k, sum_p, p = 3, t;
	if (m <= 2 || n <= 0)
		cout << "Таких чисел нет";
	else
	{
		cout << "2 ";
		while (i < n)
		{
			sum_p = 0;
			k = 0;
			for (j = 2; j <= sqrt (p); j++)
				if (p%j == 0)
					k++;
			if (k == 0)
			{
				t = p;
				while (t != 0)
				{
					sum_p = sum_p + t%10;
					t = t/10;
				}
				if (sum_p < m)
				{
					cout << p << " ";
					i++;
				}
			}
			p+=2;
		}
	}
	cout << endl;
	return 0;
}

