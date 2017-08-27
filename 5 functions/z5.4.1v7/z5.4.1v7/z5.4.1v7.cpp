// z5.4.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void solveqn (double (*p_func) (double), double a = -2, double b = 1, double e = 0.000001);
double myfun (double x);
double der (double x, double (*p_func) (double));

int _tmain(int argc, _TCHAR* argv[])
{
	solveqn (myfun);
	return 0;
}

double myfun (double x)
{
	return pow (x + 3, 3) - 8;
}

double der (double x, double (*p_func) (double))
{
	const double dx = 0.00001;
	double dy = p_func (x + dx) - p_func (x);
	double pr = dy / dx;
	return pr;
}

void solveqn (double (*p_func) (double), double a, double b, double e)
{
	int k_iter = 0;
	double x = (b - a) / 2;
	double func = p_func (x);
	double pr = der (x, myfun);
	double x0;
	do
	{
		x0 = x;
		x -= func / pr;
		func = p_func (x);
		pr = der (x, myfun);
		k_iter ++;
	}
	while (abs (x - x0) > e);
	cout << "k_iter = " << k_iter << endl;
	cout << "x = " << x << endl;
	cout << "F(x) = " << func << endl;
}
