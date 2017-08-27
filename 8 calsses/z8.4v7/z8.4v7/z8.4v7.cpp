// z8.4v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "list.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int m, n;
	cout << "m = ";
	cin >> m;
	cout << "n = ";
	cin >> n;
	List <> list1 (m), list2 (n), list3;

	cout << list1;
	cout << list2;
	list3.merge(list1, list2);
	cout << list3;
	return 0;
}

