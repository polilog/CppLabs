// z8.8v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "binary.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Binary a, b;
	cin >> a;
	cin >> b;
	cout << a;
	cout << b;
	Binary c = a + b;
	cout << c;
	cout << a * b;
	return 0;
}

