// z2.4v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	double x, sum  = 0, s;
	int k = 1;
	cout << "x=";
	cin >> x;
	s = -0.5*x*x; 
	const double eps = 0.000001;
	while (abs(s) > eps)
	{
		sum += s;
		k++;
		s *= -x*x/(2.*k) ;
	}
	cout << "sum=" << sum << endl;
	cout << "k=" << k - 1 << endl;
	return 0;
}

