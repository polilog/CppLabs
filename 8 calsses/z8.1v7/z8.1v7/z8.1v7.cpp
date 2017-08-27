// z8.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "binary.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Binary a("1001"), b(123), c;
	//cin >> c;
		c = a + b;
	cout << a << " " << b << " " << c;

	return 0;
}

