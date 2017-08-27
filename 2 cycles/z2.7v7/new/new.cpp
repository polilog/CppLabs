// z2.7v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double x, y1, y2;
	const double x0 = 1, xm = 5, dx = 0.5;
	int i, n;
	x = x0;
	cout << "n=";
	cin >> n;
	while (x <= xm)
	{
		double x2 = x * x;
		double add = x;
		double C = 1;
		y1 = 10 + add;
		int kol_sum1 = 1, kol_umn1 = 0;
		for (i = 2; i < n + 1; i++)
		{
			C += 2;
			add *= -1 * x2;
			y1 += add * C;
			kol_sum1 += 2;
			kol_umn1 += 3;
		}

		C = 2 * n - 1;
		y2 = -C;
		int kol_sum2 = 2, kol_umn2 = 2;
		for (i = n - 1; i > 0; i--)
		{
			C -= 2;
			y2 = -1 * (C + y2 * x2);
			kol_sum2 +=2;
			kol_umn2 += 2;
		}
		y2 = -y2 * x + 10;
		kol_sum2 += 2;
		kol_umn2 ++;
		cout << "x = " << x <<endl;
		cout << "y1 = " << y1 << endl;
		cout << "Umn: " << kol_umn1 << endl;
		cout << "Sum: " << kol_sum1 << endl;
		cout << "y2=" << y2 << endl;
		cout << "Umn: " << kol_umn2 << endl;
		cout << "Sum: " << kol_sum2 << endl;
		x += dx;
	}
	return 0;
}