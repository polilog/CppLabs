#include "stdafx.h"
#include "graph.h"

void erase(list *&adj)
{
	list *p = NULL;
	while (adj)
	{
		p = adj;
		adj = adj->next;
		delete p;
	}
}

void insert(list *&adj, int v)
{
	list *nv = new list;
	nv->key = v;
	nv->next = NULL;
	if (!adj)
		adj = nv;
	else
	{
		list *t = adj;
		while (t->next)
			t = t->next;
		t->next = nv;
	}
}