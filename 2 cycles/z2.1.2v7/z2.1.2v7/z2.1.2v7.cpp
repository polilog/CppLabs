// z2.1.2v7.cpp: ���������� ����� ����� ��� ����������� ����������.
//7.	���������� ����� �� ����� k ���� ������� ����� ���������
//�������������� ������������� ����� ����� ���� ����� ����� ����� �����. 

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double d;
	int n, i, k;
	cout << "d=";
	cin >> d;
	cout << "k=";
	cin >> k;
	n = static_cast<int>(d);
	int sum_n = 0, sum_r = 0;
	while (n != 0)
	{
		sum_n = sum_n + n % 10;
		n = n/10;
	}
	for (i = 0; i < k; i++ )
	{
		sum_r += static_cast<int>(10*d)%10;
		d = 10*d;
	}
	if (sum_n == sum_r)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}

