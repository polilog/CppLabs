// z1.4v7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;
//�� ���� (k, l) ����� �����, �� ���� (m, n) � �����. 

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, l, m, n;
	cout << "��������� �����" << endl;
	cout << "k=";
	cin >> k;
	cout << "l=";
	cin >> l;
	cout << "��������� �����" << endl;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	int i = 0;
	if (k > 8 || l > 8 || k < 1 || l < 1 || m > 8 || m < 1 || n > 7 || n < 2)
		cout << "������" << endl;
	else
	{
		if (abs(m - k) == 1  && l == n + 1)
			cout << "1. ����� ���� �����" << endl;
		else 
		{
			cout << "1. ����� �� ���� �����" << endl;
			i++;
		}
		if (k == m || l == n)
			cout << "   ����� ���� �����" << endl;
		else 
		{
			if (abs (k - m) == abs (l - n))
				cout << "   ����� ���� �����" << endl;
			else
			{
				cout << "   ����� �� ���� �����" << endl;
				i++;
			}
		}
		if (i == 2)
		{
			if (l == n + 1)
				cout << "2. ��� ����� ��������, ����� �������� �� �� ����" << endl;
			else 
			{
				if (abs (k - m) == abs (l - n - 1))
					cout << "2. ��� ����� ��������" << endl;
				else
					cout << "2. ��� ����� ����������" << endl;
			}
			if (abs(k - m) == 1 || l == n + 1)
				cout << "   ��� ����� ��������" << endl;
			else 
				cout << "   ��� ����� ����������" << endl;
		}
			
	}
	return 0;
}

