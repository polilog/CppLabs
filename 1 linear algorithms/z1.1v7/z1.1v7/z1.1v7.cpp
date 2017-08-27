// z1.1v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int s, t;
	double x, y;
	setlocale(LC_ALL, "rus");	
	cout << "s=";
	cin >> s;
	cout << "t=";
	cin >> t;
	cout << "x=";
	cin >> x;
	if (x > 0 && log (pow (x, 3))>0 && pow (x, s)+1 > 0)
	{
		y = (1 + pow (x, t))/(log( pow (x, 3)) * pow (pow (x, s) + 1, 0.5));
		cout << "y=" << y << endl;
	}
	else
		cout << "Ќедопустимое значение x" << endl;
	return 0;
}

