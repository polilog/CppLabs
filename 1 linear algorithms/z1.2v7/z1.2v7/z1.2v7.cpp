// z1.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	double R, x, y;
	cout << "R=";
	cin >> R;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	if (pow (x+R, 2) + pow (y, 2) <= pow (R, 2) && x >= -R && y >= 0)
		cout << "Принадлежит" << endl;
	else
		if (pow (x-R, 2) + pow (y, 2) <= pow (R, 2) && x <= R && y <= 0)
			cout << "Принадлежит" << endl;
		else 
			cout << "Не принадлежит" << endl;
	return 0;
}

