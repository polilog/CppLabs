// z5.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int& get_number (int a[], int size, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	srand (time (NULL));
	int a[100];
	int n;
	cout << "n = ";
	cin >> n;
	int size;
	cout << "size = ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		a[i] = rand () % 100;
		cout << a[i] << " ";
	}
	cout << endl;

	get_number (a, size, n) = 0;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

int& get_number (int a[], int size, int n)
{
	int max = 0;
	int max_pow = -1;
	for (int i = 0; i < size; i++)
	{
		bool pow = true;
		int temp = a[i];
		int temp_pow = -1;
		if (temp == 1)
			temp_pow = 0;
		while (temp > 1)
		{
			if (temp % n != 0)
			{
				pow = false;
				break;
			}
			else 
			{
				temp /= n;
				temp_pow ++;
			}
		}
		if (pow && temp_pow > max_pow)
		{
			max_pow = temp_pow;
			max = i;
		}
	}

	if (max_pow != -1)
		return a[max];
	else
	{
		for (int i = 0; i < size; i++)
			if (a[i] > a[max])
				max = i;
		return a[max];
	}
}