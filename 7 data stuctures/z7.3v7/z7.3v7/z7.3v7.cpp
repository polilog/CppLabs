// z7.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

struct list
{
	int data;
	list *next;
};

void find_gt(list *top, int key, list *&pv, list *&ppv);
void add(list *&top, int key);
void show(list *top);
void create(list *&top);
void delete_list(list *&);
void merge(list *, list *, list *&);
void insert(list *&, list *&);


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	list *top1 = NULL, *top2 = NULL, *top = NULL;
	create(top1);
	create(top2);
	show(top1);
	show(top2);

	merge(top1, top2, top);
	show(top);

	delete_list(top1);
	delete_list(top2);
	delete_list(top);

	return 0;
}

//занесение элемента в список
void add(list *&top, int key)
{
	list *nv, *pv = NULL, *ppv = NULL;
	nv = new list;
	nv->data = key;
	nv->next = NULL;
	if (!top)
		top = nv;
	else
	{
		if (top->data >= key)
		{
			nv->next = top;
			top = nv;
		}
		else
		{
			find_gt(top, key, pv, ppv);
			nv->next = pv;
			ppv->next = nv;
		}
	}
}

//поиск позиции элемента
void find_gt(list *top, int key, list *&pv, list *&ppv)
{
	pv = top;
	ppv = top;
	while (pv && pv->data <= key)
	{
		ppv = pv;
		pv = pv->next;
	}
}

//создание списка
void create(list *&top)
{
	int n;
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 51;
		cout << a << " ";
		add(top, a);
	}
	cout << endl << endl;
}

//вывод на экран
void show(list *top)
{
	while (top)
	{
		cout << top->data << " ";
		top = top->next;
	}
	cout << endl;
}

void delete_list(list *&top)
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

void merge(list *top1, list *top2, list *&top)
{
	while (top1 && top2)
	{
		if (top1->data < top2->data)
			insert(top1, top);
		else
		{
			if (top2->data < top1->data)
				insert(top2, top);
			else
			{
				int temp = top1->data;
				while (top1 && top1->data == temp)
					top1 = top1->next;
				while (top2 && top2->data == temp)
					top2 = top2->next;
			}
		}
	}
	while (top1)
		insert(top1, top);
	while (top2)
		insert(top2, top);
}

void insert(list *&top1, list *&top)
{
	if (!top)
	{
		top = new list;
		top->next = NULL;
		top->data = top1->data;
	}
	else
	{
		list *cur = new list;
		cur->next = NULL;
		cur->data = top1->data;
		list *last = top;
		while (last->next)
			last = last->next;
		last->next = cur;
	}
	top1 = top1->next;
}