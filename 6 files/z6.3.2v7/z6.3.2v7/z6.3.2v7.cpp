// z6.3.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef double my_type;

void binary(my_type);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "d = ";
	my_type d;
	cin >> d;
	binary(d);
	return 0;
}

void binary(my_type d)
{
	union
	{
		my_type num;
		struct
		{
			unsigned char a0:1;
			unsigned char a1:1;
			unsigned char a2:1;
			unsigned char a3:1;
			unsigned char a4:1;
			unsigned char a5:1;
			unsigned char a6:1;
			unsigned char a7:1;
		} byte[sizeof(my_type)];
	} cod;
	cod.num = d;
	cout << "bity = ";
	for (int i = sizeof(my_type) - 1; i >= 0; i--)
	{
		cout << (int)cod.byte[i].a7 << (int)cod.byte[i].a6 << (int)cod.byte[i].a5 << (int)cod.byte[i].a4 
			 << (int)cod.byte[i].a3 << (int)cod.byte[i].a2 << (int)cod.byte[i].a1 << (int)cod.byte[i].a0;
	}
	cout << endl;
}