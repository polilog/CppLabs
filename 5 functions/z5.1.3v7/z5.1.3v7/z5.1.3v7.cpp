// z5.1.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//4.1
int get_str(char [], int);
void find_series(char [], int, int &, int &);
void delete_series(char [], int, int, int);

//4.2
int get_number();
void check_prime(int, bool []);
void find_palindromes(int, bool []);

int _tmain(int argc, _TCHAR* argv[])
{
	//4.1
	setlocale(LC_ALL, "rus");
	const int MAX = 100;
	char str[MAX];
	int n = get_str(str, MAX);

	int first_char = 0, max_size = 0;
	find_series(str, n, first_char, max_size);
	delete_series(str, n, first_char, max_size);

	//4.2
	const int max = 10000;
	bool a[max] = {0};

	int N = get_number();
	check_prime(N, a);
	find_palindromes(N, a);

	return 0;
}

//4.1
int get_str(char str[], int MAX)
{
	cout << "Введите строку:" << endl;
	cin.getline(str, MAX);
	int n = strlen (str);
	return n;
}

void find_series(char str[], int n, int &first_char, int &max_size)
{
	int temp_size = 0;
	int temp_char = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[temp_char] == str[i])
			temp_size ++;
		else
		{
			if (temp_size > max_size)
			{
				max_size = temp_size;
				first_char = temp_char;
			}
			temp_char = i;
			temp_size = 1;
		}
	}
	if (temp_size > max_size)
	{
		max_size = temp_size;
		first_char = temp_char;
	}
}

void delete_series(char str[], int n, int first_char, int max_size)
{
	if (max_size < 2)
		cout << "Серий нет" << endl;
	else 
	{
		for (int i = first_char + max_size; i < n; i++)
			str[i - max_size] = str[i];
		str[n - max_size] = '\0';
		cout << str <<endl;
	}
}

//4.2
int get_number()
{
	unsigned int N;
	cout << "N = ";
	cin >> N;
	return N;
}

void check_prime(int N, bool a[])
{
	for (int i = 2; i <= N; i++)
		a[i] = 1;

	int n = sqrt (N);
	for (int i = 2; i <= n; i++)
		if (a[i])
			for(int j = i * 2; j <= N; j += i) 
				a[j] = 0;
}

void find_palindromes(int N, bool a[])
{
	for (int i = 0; i <= N; i++)
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
}