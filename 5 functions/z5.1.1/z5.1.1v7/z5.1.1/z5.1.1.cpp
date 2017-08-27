// z5.1.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int vvod ();
int find_digit (int, int);
void vyvod (int);

int _tmain(int argc, _TCHAR* argv[])
{
	int n = vvod ();
	vyvod (n);
}

int vvod ()
{
	int n;
	cout << "n = ";
	cin >> n;
	return n;
}

int find_digit (int number, int digit)
{
	int j = 0;
	while (number != 0)
	{
		if (number % 10 == digit)
				j++;
			number /= 10;
	}
	return j;
}

void vyvod (int number)
{
	bool find = false;
	for (int i = 0; i < 9; i++)
		if (find_digit (number, i) == 2)
		{
			find = true;
			break;
		}
	if (find)
		cout << "Da" << endl;
	else
		cout << "Net" << endl;
}

