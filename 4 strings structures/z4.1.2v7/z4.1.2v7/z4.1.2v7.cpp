// z4.1.2v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	cout << "Введите строку:" << endl;
	string str;
	getline(cin, str);
	int n = str.length();

	int max_size = 0;
	int temp_size = 0;
	int first_char = 0;
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

	if (max_size < 2)
		cout << "Серий нет" << endl;
	else 
	{
		str.erase (first_char, max_size);
		cout << str <<endl;
	}
	return 0;
}
