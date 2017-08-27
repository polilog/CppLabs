// z3.7v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int fact[10000] = {0};
	fact[0] = 1;
	int N;
	cout << "N = ";
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int temp = 0;
		for (int j = 0; j < 10000; j++)
		{
			fact[j] *= i;
			fact[j] += temp;
			if (fact[j] > 9)
			{
				temp = fact[j] / 10;
				fact[j] %= 10;
			}
			else
				temp = 0;
		}
	}
	int last = 9999;
	while (fact[last] == 0)
		last--;
	for (int i = last; i >=0; i--)
		cout << fact[i];
	cout << endl<<last<<endl;
	int kol[10] = {0};
	for (int j = last; j >= 0; j--)
		for (int  i = 0; i < 10; i++)
			if (fact[j] == i)
				kol[i]++;
	for (int i = 0; i < 10; i++)
		cout << i << ": " << kol[i] << endl;
	return 0;
}

