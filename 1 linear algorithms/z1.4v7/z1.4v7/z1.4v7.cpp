// z1.4v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;
//На поле (k, l) стоит ферзь, на поле (m, n) – пешка. 

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, l, m, n;
	cout << "Положение ферзя" << endl;
	cout << "k=";
	cin >> k;
	cout << "l=";
	cin >> l;
	cout << "Положение пешки" << endl;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	int i = 0;
	if (k > 8 || l > 8 || k < 1 || l < 1 || m > 8 || m < 1 || n > 7 || n < 2)
		cout << "Ошибка" << endl;
	else
	{
		if (abs(m - k) == 1  && l == n + 1)
			cout << "1. Пешка бьет ферзя" << endl;
		else 
		{
			cout << "1. Пешка не бьет ферзя" << endl;
			i++;
		}
		if (k == m || l == n)
			cout << "   Ферзь бьет пешку" << endl;
		else 
		{
			if (abs (k - m) == abs (l - n))
				cout << "   Ферзь бьет пешку" << endl;
			else
			{
				cout << "   Ферзь не бьет пешку" << endl;
				i++;
			}
		}
		if (i == 2)
		{
			if (l == n + 1)
				cout << "2. Ход пешки возможен, после которого он ее бьет" << endl;
			else 
			{
				if (abs (k - m) == abs (l - n - 1))
					cout << "2. Ход пешки возможен" << endl;
				else
					cout << "2. Ход пешки невозможен" << endl;
			}
			if (abs(k - m) == 1 || l == n + 1)
				cout << "   Ход ферзя возможен" << endl;
			else 
				cout << "   Ход ферзя невозможен" << endl;
		}
			
	}
	return 0;
}

