// z7.1.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <clocale>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int size = 10000;
	int number = 1000000;
	int *a = new int [size];
	if (!a)
		return 1;

	ofstream fout("f.txt");
	if (!fout)
	{
		cout << "File error" << endl;
		return 1;
	}
	for (int i = 0; i < number; i++)
		fout << (rand() % size + 1) << " "; 
	fout.close();

	ifstream fin("f.txt");
	if (!fin)
	{
		cout << "File error" << endl;
		return 1;
	}
	for (int i = 0; i < size; i++)
		a[i] = 0;
	int k;
	while (!fin.eof())
	{
		fin >> k;
		a[k - 1]++;
	}
	fin.close();

	ofstream gout("g.txt");
	if (!gout)
	{
		cout << "File error" << endl;
		return 1;
	}
	for (int k = size - 1; k >=0 ; k--)
		if (a[k] > 1)
			gout << k + 1 << " ";
	gout.close();
	system("start g.txt");
	delete [] a;
	return 0;
}