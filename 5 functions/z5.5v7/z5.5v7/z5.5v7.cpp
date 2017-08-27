// z5.5v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include "integr.h"

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	double s = 1;
	const double ds = 0.5;
	const double dt = 0.2;
	cout << setw (10) << "s" << setw (10) << "t" << setw (10) << "Int" << setw (10) << "k_iter" << endl;
	for (int i = 0; i < 7; i++)
	{
		double t = 0.4;
		for (int j = 0; j < 5; j++)
		{
			integrate (myfun, s, t);
			t += dt;
		}
		s += ds;
	}
	return 0;
}



