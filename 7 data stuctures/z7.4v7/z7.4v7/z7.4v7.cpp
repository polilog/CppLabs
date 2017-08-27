// z7.4v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

struct list
{
	double data;
	list *next;
	list *prior;
};

void add(list *&, list *&, double);
void find(list *, double, list *&, list *&);
void show(list *);
double calc(list *, list *, int);
void delete_list(list *&);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	
	list *top = NULL, *end = NULL;
	int n;
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
		add(top, end, double (rand() % 41) / (rand() % 11 + 1));
	show(top);
	double result;
	result = calc(top, end, n);
	cout << "result = " << result << endl;
	delete_list(top);
	return 0;
}

void add(list *&top, list *&end, double key)
{
	list *nv, *pv = NULL, *ppv = NULL;
	nv = new list;
	nv->data = key;
	nv->next = NULL;
	nv->prior = NULL;
	if (!top)
	{
		top = nv;
		end = nv;
	}
	else // сортировать не нужно!
	{
		if (top->data >= key)
		{
			nv->next = top;
			top->prior = nv;
			top = nv;
		}
		else
		{
			find(top, key, pv, ppv);
			nv->next = pv;
			nv->prior = ppv;
			if (pv)
				pv->prior = nv;
			else
				end = nv;
			ppv->next = nv;
		}
	}
}

void find(list *top, double key, list *&pv, list *&ppv)
{
	pv = top;
	ppv = top;
	while (pv && pv->data <= key)
	{
		ppv = pv;
		pv = pv->next;
	}
}

void show(list *top)
{
	while (top)
	{
		cout << top->data << " ";
		top = top->next;
	}
	cout << endl;
}

double calc(list *top, list *end, int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += (top->data) * (end->data);
		top = top->next;
		end = end->prior;
	}
	return result;
}

void delete_list(list *& top)
{
	list *pv = NULL;
	while (top)
	{
		pv = top;
		top = top->next;
		delete pv;
	}
	pv = NULL;

}
