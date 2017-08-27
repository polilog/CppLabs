// z8.5v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dlist.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int n;
	cout << "n = ";
	cin >> n;
	cout << "Введите элементы списка" << endl;
	DList <int> list(2 * n);
	int res = list.calc();
	cout << "res = " << res << endl;
	cout << list;
	return 0;
}

