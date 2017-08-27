// z1.3v7-2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	double x1, x2, x3, x4, t;
	cout << "x1=";
	cin >> x1;
	cout << "x2=";
	cin >> x2;
	cout << "x3=";
	cin >> x3;
	cout << "x4=";
	cin >> x4;

	t = x1;
	x1 = (x1 < x2) ? x2 : x1;
	x2 = (t < x2) ? t : x2;

	t = x2;
	x2 = (x2 < x3) ? x3 : x2;
	x3 = (t < x3) ? t : x3;

	t = x3;
	x3 = (x3 < x4) ? x4 : x3;
	x4 = (t < x4) ? t : x4;

	t = x1;
	x1 = (x1 < x2) ? x2 : x1;
	x2 = (t < x2) ? t : x2;

	t = x2;
	x2 = (x2 < x3) ? x3 : x2;
	x3 = (t < x3) ? t : x3;

	t = x1;
	x1 = (x1 < x2) ? x2 : x1;
	x2 = (t < x2) ? t : x2;

 	cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
	return 0;
}

