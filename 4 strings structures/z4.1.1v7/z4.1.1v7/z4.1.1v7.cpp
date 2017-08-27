// z4.1.1v7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char str[100];
	setlocale(LC_ALL, "rus");
	cout << "������� ������:" << endl;
	cin.getline(str, 100);
	int n = strlen (str);
	
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
		cout << "����� ���" << endl;
	else 
	{
		for (int i = first_char + max_size; i < n; i++)
			str[i - max_size] = str[i];
		str[n - max_size] = '\0';
		cout << str <<endl;
	}

	return 0;
}

