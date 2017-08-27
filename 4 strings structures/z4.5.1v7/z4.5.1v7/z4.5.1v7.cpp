// z4.5.1v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int max = 100;
	char str[max];
	char sep[] = " .,:;?!-()";

	setlocale (LC_ALL, "rus");
	cout << "¬ведите строку:" << endl;
	cin.getline (str, max);

	const int N = 20;
	char *tok[N];
	char *next_tok = NULL;

	int n = 0;
	tok[n] = strtok_s (str, sep, &next_tok);
	while (tok[n] != NULL)
	{
		n++;
		tok[n] = strtok_s (NULL, sep, &next_tok);
	}
	for (int i = 0; i < n; i++)
		cout << tok[i] << endl;
	return 0;
}

