// z8.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "complex.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Complex a, b;
	cin >> a;
	cin >> b;
	cout << a + b;
	cout << a * b;
	return 0;
}

