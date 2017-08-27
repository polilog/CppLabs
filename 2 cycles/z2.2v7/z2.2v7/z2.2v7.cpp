// z2.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	double x, y, s, y0;
	const double eps = 0.000001, x0 = -0.5, xn = 0.5, dx = 0.1;
	x = x0;
	while (x <= xn)
	{
		y = 0;
		i = 0;
		s = 1;
		while (abs(s) > eps)
		{
			y += s;
			i++;
			s = (s * x)/ (2.*i);
			if (i > 1)
				s = s * (-1);
			if (i > 2)
				s = s * (2.*(i - 2) + 1.);		
		}
		y0 = pow (1 + x, 0.5);
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "y0=" << y0 << endl;
		cout << "i=" << i << endl;
		cout << endl;
		x += dx;
	}
	return 0;
}

