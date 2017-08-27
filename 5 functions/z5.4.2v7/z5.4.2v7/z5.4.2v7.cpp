// z5.4.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void solveqn (double (*p_func) (double, double), double s, double a = 0, double b = 2, double e = 0.000001);
double myfun (double x, double s);
double der (double x, double s, double (*p_func) (double, double));

int _tmain(int argc, _TCHAR* argv[])
{
	cout << setw(7) << "S" << setw(13) << "X" << setw(15) << "F(x)" << setw(7) << "k_iter" << endl;
	for (int i = 0; i < 5; i++)
	{
		double s = 2.8 + 0.1 * i;
		solveqn (myfun, s);
	}
	return 0;
}

double myfun (double x, double s)
{
	const double pi = 3.1415;
	return cos (pi * x) - pow (x, s);
}

double der (double x, double s, double (*p_func) (double, double))
{
	const double dx = 0.00001;
	double dy = p_func (x + dx, s) - p_func (x, s);
	double pr = dy / dx;
	return pr;
}

void solveqn (double (*p_func) (double, double), double s, double a, double b, double e)
{
	int k_iter = 0;
	double x = (b - a) / 2;
	double func = p_func (x, s);
	double pr = der (x, s, myfun);
	double x0;
	do
	{
		x0 = x;
		x -= func / pr;
		func = p_func (x, s);
		pr = der (x, s, myfun);
		k_iter ++;
	}
	while (abs (x - x0) > e);
	cout << setw(7) << s << setw(13) << x << setw(15) << func << setw(7) << k_iter << endl;
}
