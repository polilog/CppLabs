// z6.3.1v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

typedef double my_type;

union number
{
	my_type d;
	char ch[sizeof(my_type)];
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	number n;
	cout << "¬ведите число: ";
	cin >> n.d;
	bool bit[8 * sizeof(my_type)];
	for (int i = 0; i < sizeof(my_type); i++)
		for (int j = 0; j < 8; j++)
			bit[8 * i + j] = (n.ch[i] >> j) & 1;
	for (int i = 8 * sizeof(my_type) - 1; i >= 0; i--)
		cout << bit[i];
	cout << endl;
	return 0;
}

