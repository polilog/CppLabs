// z5.3v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

int cycle (int n);
int recursion (int n);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	int n;
	cout << "¬ведите n = " ;
	cin >> n;

	int a_cyc = cycle (n);
	cout << "a = " << a_cyc << endl; 
	int a_rec = recursion (n);
	cout << "a = " << a_rec << endl;

	return 0;
}

int cycle (int n)
{
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;

	switch (n)
	{
		case 1: 
			return a1;
			break;
		case 2:
			return a2;
			break;
		default:
			{
				for (int i = 0; i < n - 3; i++)
				{
					int temp = 3 * a3 + 2 * a2 + a1;
					a1 = a2;
					a2 = a3;
					a3 = temp;
				}
				return a3;
			}
			break;
	
	}
}

int recursion(int n)
{

	if (n>3){
		return 3 * recursion (n - 1) + 2 * recursion (n - 2) + recursion (n - 3);	
	}else{
		return n;
	}

	/*
	switch (n)
	{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		default:
			return 3 * recursion (n - 1) + 2 * recursion (n - 2) + recursion (n - 3);
			break;
	}
	*/
}

