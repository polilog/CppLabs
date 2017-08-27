// z4.3.1v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");

	const int max = 100;
	char string[max];
	const char sep[] = " .,;:!?-()";

	cout << "¬ведите строку:" << endl;
	cin.getline (string, max);

	char new_string[max] = "";
	char *token = NULL;
	char *next_token = NULL;

	token = strtok_s (string, sep, &next_token);
	while (token != NULL)
	{
			int err = 0;
			for (unsigned int i = 0; i < strlen (token); i++)
			{
				for (unsigned int j = i + 1; j < strlen (token); j++)
					if (token[i] == token[j])
					{
						err = 1;
						break;
					}
				if (err == 1)
					break;
			}
			if (err == 0)
			{
				strcat_s (new_string, max, token);
				strcat_s (new_string, max, " ");
			}
			token = strtok_s (NULL, sep, &next_token);
	}
	for (unsigned int i = 0; i < strlen (new_string); i++)
		cout << new_string[i];
	return 0;
}

