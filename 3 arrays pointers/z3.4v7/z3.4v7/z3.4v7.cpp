// z2.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>
#include <climits>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int m, n;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	int k = 0;
	if (m <= 2 || n <= 0)
		cout << "Таких чисел нет";
	else
	{
		//const int N = 200;
		const int N = 10000; 
		bool a[N] = {0};                                                                                                            							//заполним все ячейки числом 1
		for(int i = 2; i < N; i++) 
			a[i] = 1;
		int p = sqrt(double(N)); 
		for(int i = 2; i <= p; i++)
			if (a[i])
				for(int j = i * 2; j < N; j += i) 
					a[j] = 0;
		for(int i = 2; i < N, k < n; i++) 
			if (a[i])
			{
				int sum = 0;
				int t = i;
				while (t != 0)
				{
					sum += t % 10;
					t /= 10;
				}
				if (sum < m)
				{
					k++;
					cout << i << " ";
				}
			}
	}
	cout << endl;
	return 0;
}
