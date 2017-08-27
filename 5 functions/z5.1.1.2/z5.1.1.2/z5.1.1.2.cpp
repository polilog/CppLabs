// z5.1.1.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void get_number(double &, int &);
int find_n(double);
int find_r(double, int);
void compare(int *, int *);

int _tmain(int argc, _TCHAR* argv[])
{
	double d;
	int k;
	get_number(d, k);
	int sum_n = find_n(d);
	int sum_r = find_r(d, k);
	compare(&sum_n, &sum_r);
	
	return 0;
}

void get_number(double &d, int &k)
{
	cout << "d=";
	cin >> d;
	cout << "k=";
	cin >> k;
}

int find_n(double d)
{
	int sum_n = 0;
	int n = static_cast<int>(d);
	while (n != 0)
	{
		sum_n = sum_n + n % 10;
		n = n/10;
	}
	return sum_n;
}

int find_r(double d, int k)
{
	int sum_r = 0;
	for (int i = 0; i < k; i++ )
	{
		sum_r += static_cast<int>(10*d)%10;
		d = 10*d;
	}
	return sum_r;
}

void compare(int *sum_n, int *sum_r)
{
	if (*sum_n == *sum_r)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
