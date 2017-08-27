// z5.8v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

const int size = 8;
int results = 0;
int board[size][size];

void show_board (ofstream &);
void set_rook (int, ofstream &);
bool try_rook(int, int);

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream fout("f.txt");
	if(!fout)
	{
		cout << "File error" << endl;
		return 1;
	}

	set_rook(0, fout);
	fout << results;

	fout.close();
	return 0;
}

void show_board (ofstream &fout)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fout << board[i][j];
		fout << endl;
	}
	fout << endl;
}

bool try_rook(int a, int b)
{
	for (int i = 0; i < a; i++)
		if (board[i][b])
			return false;
	return true;
}

void set_rook (int a, ofstream &fout)
{
	if (a == size)
	{
		show_board(fout);
		results++;
	}
	else
		for (int i = 0; i < size; i++)
			if(try_rook(a, i))
			{
				board[a][i] = 1;
				set_rook (a + 1, fout);
				board[a][i] = 0;
			}
}