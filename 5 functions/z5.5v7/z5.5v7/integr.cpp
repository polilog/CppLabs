#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include "integr.h"

using namespace std;

double myfun (double x, double s, double t)
{
	return (tan(x*x) + sqrt(x)) /  (t * log10 (x + s));
}

void integrate (double (*p_func) (double, double, double), double s, double t, double a, double b, double e)
{
	int n = 4;
	double s1 = 0, s2 = 0;
	int k_iter = 0;
	do
	{
		s2 = s1;
		n *= 2;
		s1 = sum (p_func, s, t, n);
		k_iter ++;
	}
	while (abs (s1 - s2) > e);
	double integral = s1;
	cout << setw (10) << s << setw (10) << t << setw (10) << integral << setw (10) << k_iter << endl;
}

double sum (double (*p_func) (double, double, double), double s, double t, int n, double a, double b)
{
	const double h = (b - a) / n;
	double x = a;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += p_func (x + h / 2, s, t);
		x += h;
	}
	sum *= h;
	return sum;
}