// z2.6v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int k, n, c = 0, i;
	cout << "k = ";
	cin >> k;
	for (i = 1; c < k; i++)
	{
		n = i * i * i;
		while (n != 0)
		{
			n /= 10;
			c++;
		}
	}
	i--;
	n = i * i * i;
	n /= pow (10, c - k);
	int K = n % 10;
	cout << "K = " << K << endl;
	return 0;
}

