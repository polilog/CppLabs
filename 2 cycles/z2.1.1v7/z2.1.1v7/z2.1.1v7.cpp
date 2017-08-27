// z2.1.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int n, i, j, t;
	cout << "n=";
	cin >> n;
	for (i = 0; i < 9; i++)
	{
		t = n;
		j = 0;
		while (t != 0)
		{
			if (t % 10 == i)
				j++;
			t /= 10;
		}
		if (j == 2)
		{
			cout << "Yes" << endl;
			break;
		}
	}
	if (j != 2)
		cout << "No" << endl;
	return 0;
}

