// z2.5v7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n, a , b, i, k, l;
	double d;
	cout << "n = ";
	cin >> n;
	if (n > 1)
	{
		cout << "������� ������������������:" << endl;
		cin >> a;
		b = a;
		cin >> a;
		d = (1.*a)/(1.*b);
		k = 2;
		l = 2;
		for (i = 2; i < n; i++)
		{
			b = a;
			cin >> a;
			if (abs(d - (1.*a)/(1.*b)) < 0.00001)
				k++;
			else
			{
				if (l < k)
					l = k;
				d = (1.*a)/(1.*b);
				k = 2;
			}
		}
		cout << "���������� ���������:" << l << endl;
	}
	else
	{
		cin >> a;
		cout << "���������� ���������: 1" << endl;
	}
	return 0;
}

