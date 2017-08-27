#include "functions.h"
#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <clocale>

using namespace std;

void asc_ord (int n, int a[])
{
	srand (time (NULL));
	a[0] = rand () % 21 - 10;
	cout << a[0] << " ";
	for (int i = 1; i < n; i ++)
	{
		a[i] = a[i-1] + rand () % 6;
		cout << a[i] << " ";
	}
	cout << endl;
}

void des_ord (int n, int a[])
{
	srand (time (NULL));
	a[0] = rand () % 21;
	cout << a[0] << " ";
	for (int i = 1; i < n; i ++)
	{
		a[i] = a[i-1] - rand () % 6;
		cout << a[i] << " ";
	}
	cout << endl;
}

void rand_ord (int n, int a[])
{
	srand (time (NULL));
	for (int i = 0; i < n; i ++)
	{
		a[i] = rand () % 26 - 5;
		cout << a[i] << " ";
	}
	cout << endl;
}

void q_sort (int left, int right, int a[], int &comp, int &swap)
{
	int i = left, j = right;
	int mid = a[(left + right) / 2];
	do
	{
		while (a[i] < mid)
		{
			comp++;
			i++;
		}
		while (a[j] > mid)
		{
			comp++;
			j--;
		}
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			swap++;
			i ++;
			j --;
		}
	}
	while (i < j);
	if (left < j)
		q_sort (left, j, a, comp, swap);
	if (i < right)
		q_sort (i, right, a, comp, swap);
}

void s_sort (int n, int a[])
{
	int comp = 0, swap = 0;
	for (int i = 0; i < n - 1; i ++)
	{
		int index_min = i;
		for (int j = i + 1; j < n; j ++)
		{
			comp++;
			if (a[j] < a[index_min])
					index_min = j;
		}
		int min = a[index_min];
		if (index_min != i)
		{
			a[index_min] = a[i];
			a[i] = min;
			swap++;
		}
	}
	for (int i = 0; i < n; i ++)
		cout << a[i] << " ";
	cout << endl;
	cout << "Сравнения: " << comp << endl;
	cout << "Перемещения: " << swap << endl;
}

bool comp (int a, int b)
{
	if (a < b)
		return true;
	else
		return false;
}