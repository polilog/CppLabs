// z8.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "matrix.h"

template <class T>
void print(Matrix <T> **p, int n)
{
	for (int i = 0; i < n; i++)
		cout << *p[i];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "n = ";
	cin >> n;

	Matrix <> a (n, n), b (n, n);
	cin >> a;
	cin >> b;

	Matrix <> ab(a * b), ba(b * a); 
	Matrix <> c(ab + ba);

	Matrix <> **p = new Matrix <> * [5];
	p[0] = &a;
	p[1] = &b;
	p[2] = &ab;
	p[3] = &ba;
	p[4] = &c;
	print(p, 5);
	delete [] p;

	return 0;
}

