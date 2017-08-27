// z1.5v7-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	double x1, y1, x2, y2, x3, y3, x, y;
	cout << "Введите координаты вершин" << endl;
	cout << "x1=";
	cin >> x1;
	cout << "y1=";
	cin >> y1;
	cout << endl;
	cout << "x2=";
	cin >> x2;
	cout << "y2=";
	cin >> y2;
	cout << endl;
	cout << "x3=";
	cin >> x3;
	cout << "y3=";
	cin >> y3;
	cout << endl;
	cout << "Введите координаты точки" << endl;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	double p1, p2, p3;
	p1 = (x2-x1)*(y-y1)-(y2-y1)*(x-x1);
	p2 = (x3-x2)*(y-y2)-(y3-y2)*(x-x2);
	p3 = (x1-x3)*(y-y3)-(y1-y3)*(x-x3);
	if (p1 == 0 || p2 == 0 || p3 == 0)
		cout << "Точка лежит на одной из сторон" << endl;
	else
	{
		if (p1 > 0 && p2 > 0 && p3 > 0)
			cout << "Точка принадлежит треугольнику" << endl;
		else
			if (p1 < 0 && p2 < 0 && p3 < 0)
				cout << "Точка принадлежит треугольнику" << endl;
			else
				cout << "Точка не принадлежит треугольнику" << endl;
	}
	return 0;
}

