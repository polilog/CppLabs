// z4.2.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int N;
	cout << "N = ";
	cin >> N;

	const int max = 10000;
	bool a[max] = {0};
	for (unsigned int i = 2; i <= N; i++)
		a[i] = 1;

	unsigned int n = sqrt (N);
	for (unsigned int i = 2; i <= n; i++)
		if (a[i])
			for(unsigned int j = i * 2; j <= N; j += i) 
				a[j] = 0;

	for (unsigned int i = 0; i <= N; i++)
		if (a[i])
		{
			string str;
			int j = 0, numb = i;
			do
			{
				str += char ('0' + numb % 2);
				numb /= 2;
				j++;
			}
			while (numb > 0);
			int err = 0;
			for(int k = 0; k < j / 2; k++)
				{	
					if (str[k] != str[j-k-1])
					{
						err++;
						break;
					}
				}
			if (err == 0)
			{
				cout << setw(5) << i;
				cout << setw(20) << str << endl;
			}
		}
	return 0;
}

