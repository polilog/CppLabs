// z4.4.1v7.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	setlocale (LC_ALL, "rus");	//����
	cout << "������� ������:" << endl;
	cin.getline (str, max);

	const int N = 20;
	char *tok[N];
	char *next_tok = NULL;

	int n = 0;		//��������� �� �������
	tok[n] = strtok_s (str, sep, &next_tok);
	while (tok[n] != NULL)
	{
		n++;
		tok[n] = strtok_s (NULL, sep, &next_tok);
	}

	for (int i = 0; i < n - 1; i++)		//���������� ������� ��������
	{
		int index_min = i;
		for (int j = i + 1; j < n; j++)
			if (_stricmp (tok[j], tok[index_min]) < 0)
				index_min = j;
		char *min = tok[index_min];
		tok[index_min] = tok[i];
		tok[i] = min;
	}

	for (int i = 0; i < n; i++)	//�����
		cout << tok[i] << endl;
	return 0;
}

