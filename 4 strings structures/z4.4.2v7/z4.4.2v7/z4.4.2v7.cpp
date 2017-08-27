// z4.4.2v7.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "rus");
	string  str;
	cout << "¬ведите строку:" << endl;
	getline (cin, str);
	string sep (" .,:;!?-()");
	const int N = 100;
	string result[N];

	int first = 0, last = 0;
	int n = 0;
	while (true)
	{
		first = str.find_first_not_of(sep, last);
		last = str.find_first_of(sep, first);
		if (first == string::npos)
			break;
		if (last == string::npos)
			last = str.length();
		result[n] = str.substr(first, last - first);
		n++;
	}

	for (int i = 0; i < n - 1; i++)		//сортировка простой вставкой
	{
		string min = result[i];
		int index_min = i;
		for (int j = i + 1; j < n; j++)
			if (result[j] < min)
			{
				min = result[j];
				index_min = j;
			}
		result[index_min] = result[i];
		result[i] = min;
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << endl;
	return 0;
}

