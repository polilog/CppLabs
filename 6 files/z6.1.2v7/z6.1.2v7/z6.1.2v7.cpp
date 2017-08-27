// z6.1.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

void rand_numb (ofstream &, int);

int create_file (ofstream &);

void read_file (int even[], int odd[], ifstream &);

void create_new_file (int even[], int odd[], int, ofstream &);

void show_file (ifstream &, int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	ofstream fout ("f.bin", ios::binary);
	if (!fout)
	{
		cout << "File error" << endl;
		return 1;
	}

	int N = create_file(fout);

	ifstream fin ("f.bin", ios::binary);
	if (!fin)
	{
		cout << "File error" << endl;
		return 1;
	}

	const int n = 100;
	int even[n], odd[n];
	read_file(even, odd, fin);

	ofstream gout ("g.bin", ios::binary);
	if (!gout)
	{
		cout << "File error" << endl;
		return 1;
	}

	create_new_file(even, odd, N, gout);

	ifstream gin ("g.bin", ios::binary);
	if (!gout)
	{
		cout << "File error" << endl;
		return 1;
	}
	show_file (gin, N);
	gin.close();

	return 0;
}

void rand_numb (ofstream &fout, int n)
{
	int even = 0, odd = 0, el;
	while (even < n / 2 && odd < n / 2)
	{
		el = rand() %  101;
		fout.write(reinterpret_cast <char*> (&el), sizeof (int));
		if (el % 2 == 0)
			even++;
		else 
			odd++;
	}
	if (even == n / 2)
		for (int k = odd; k < n / 2; k++)
		{
			el = 2 * (rand() % 50) + 1;
			fout.write(reinterpret_cast <char*> (&el), sizeof (int));
		}
	else
		for (int k = even; k < n / 2; k++)
		{
			el = 2 * (rand() % 50);
			fout.write(reinterpret_cast <char*> (&el), sizeof (int));
		}
}

int create_file(ofstream &fout)
{
	int n;
	do
	{
		cout << "Введите количество чисел в файле: ";
		cin >> n;
		if (n % 2 == 1)
			cout << "Количество чисел в файле должно быть четным" << endl;
	}
	while (n % 2 == 1);
	rand_numb (fout, n);
	fout.close();
	return n;
}

void read_file (int even[], int odd[], ifstream &fin)
{
	int x;
	int i = 0, j = 0;
	while (!fin.eof())
	{
		fin.read(reinterpret_cast<char*>(&x), sizeof (int));
		if (x % 2 == 0)
		{
			even[i] = x;
			i++;
		}
		else
		{
			odd[j] = x;
			j++;
		}
	}
	fin.close();
}

void create_new_file(int even[], int odd[], int n, ofstream &gout)
{
	for (int k = 0; k < n / 2; k++)
	{
		gout.write (reinterpret_cast<char*>(&odd[k]), sizeof (int));
		gout.write (reinterpret_cast<char*>(&even[k]), sizeof (int));
	}
	gout.close();
}

void show_file (ifstream &gin, int n)
{
	for (int i = 0; i < n; i++)
	{
		int x;
		gin.read(reinterpret_cast<char*>(&x), sizeof (int));
		cout << x << " ";
	}
	cout << endl;
}
