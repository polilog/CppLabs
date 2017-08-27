// z4.4.1v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int max  = 100;
	char str[max];
	char sep[] = " .,:;?!-()";

	setlocale (LC_ALL, "rus");	//ввод
	cout << "¬ведите строку:" << endl;
	cin.getline (str, max);

	const int N = 20;
	char *tok[N];
	char *next_tok = NULL;

	int n = 0;		//разбиение на лексемы
	tok[n] = strtok_s (str, sep, &next_tok);
	while (tok[n] != NULL)
	{
		n++;
		tok[n] = strtok_s (NULL, sep, &next_tok);
	}

	for (int i = 0; i < n - 1; i++)		//сортировка простой вставкой
	{
		int index_min = i;
		for (int j = i + 1; j < n; j++)
			if (_stricmp (tok[j], tok[index_min]) < 0)
				index_min = j;
		char *min = tok[index_min];
		tok[index_min] = tok[i];
		tok[i] = min;
	}

	for (int i = 0; i < n; i++)	//вывод
		cout << tok[i] << endl;
	return 0;
}

