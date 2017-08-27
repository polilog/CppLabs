// z8.6v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	int n;
	cout << "n = ";
	cin >> n;
	Tree <> t(n);
	cout << t;
	int *level = NULL;
	int depth = t.tree_depth();
	level = new int [depth];
	t.preorder(level, 0);
	int max = 0;
	for (int i = 0; i < depth; i++)
		if (level[i] > level[max])
			max = i;
	cout << "max  = " << max;
	return 0;
}

