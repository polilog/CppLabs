// z1.6v7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "n=";
	cin >> n;
	bool b0 = n & 1, b1 = (n >> 1) & 1 , b15 = (n >> 15) & 1;
	cout << "��� 0:" << b0 << endl;
	cout << "��� 1:" << b1 << endl;
	cout << "��� 15:" << b15 << endl;
	n = n ^ ((1 << 7) | (1 << 15));
	cout << "n=" << n << endl;
	return 0;
}

