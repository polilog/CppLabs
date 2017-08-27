// z4.5.2v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int max = 100;
	char str[max], sep[max];
	char words[20][20];
	int number = 0;

	setlocale (LC_ALL, "rus");
	cout << "¬ведите строку:" << endl;
	cin.getline (str, max);
	cout << "¬ведите разделители:" << endl;
	cin.getline (sep, max);

	int first_char = 0, last_char = 0;
	while (true)
	{
		for (int i = last_char; str[i] != '\0'; i++)
		{
			bool find = true;
			for (int j = 0; sep[j] != '\0'; j++)
			{
				if (str[i] == sep[j])
				{
					find = false;
					break;
				}
			}
			if (find)
			{
				first_char = i;
				break;
			}
		}
		if (first_char < last_char)
			break;
		int i;
		for (i = first_char + 1; str[i] != '\0'; i++)
		{
			bool find = false;
			for (int j = 0; sep[j] != '\0'; j++)
			{
				if (str[i] == sep[j])
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				last_char = i;
				break;
			}
		}
		if (last_char < first_char)
			last_char = i;
		for (i = first_char; i < last_char; i++)
			words[number][i-first_char] = str[i];
		words[number][i-first_char] = '\0';
		number++;
	}
	for (int i = 0; i < number; i++)
		cout << words[i] << endl;
	return 0;
}

