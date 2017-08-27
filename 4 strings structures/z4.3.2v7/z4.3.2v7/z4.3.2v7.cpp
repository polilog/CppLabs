// z4.3.2v7.cpp: определ€ет точку входа дл€ консольного приложени€.
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
	string result;

	int first = 0, last = 0;
	while (true)
	{
		first = str.find_first_not_of(sep, last);
		last = str.find_first_of(sep, first);
		if (first == string::npos)
			break;
		if (last == string::npos)
			last = str.length();
		bool err = true;
		for (int i = first; i < last; i++)
			for (int j = i + 1; j < last; j++)
				if (str[i] == str[j])
				{
					err = false;
					break;
				}
		if (err)
		{
			string substring = str.substr(first, last - first);
			result += substring;
			result += "\n";
		}
	}

	cout << result;
	return 0;
}

