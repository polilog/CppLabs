// z7.6v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct list
{
	int key;
	list *next;
};

struct graph
{
	int v;
	list **adj;
};

void erase(list *&);
void insert(list *&, int);

void init(graph &, int);
void destruct(graph &);
void add_edge(graph &, int, int);
void show(graph &);
list *adj(graph &, int);

void dfs(graph &, int, bool *, bool *, int, int &);

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("data.txt");
	int V, E;
	fin >> V >> E;

	graph g;
	init(g, V);

	for (int i = 0; i < E; i++)
	{
		int v, w;
		fin >> v >> w;
		add_edge(g, v, w);
	}

	show(g);

	int n, start;
	cout << "n = ";
	cin >> n;
	cout << "start = ";
	cin >> start;
	bool *marked = new bool [g.v];
	for (int i = 0; i < g.v; i++)
		marked[i] = false;
	bool *path = new bool [g.v];
	for (int i = 0; i < g.v; i++)
		path[i] = false;

	dfs(g, start, marked, path, 0, n);
	for (int i = 0; i < g.v; i++)
		if (path[i])
			cout << i << " ";
	cout << endl;

	delete [] marked;
	delete [] path;
	destruct(g);

	return 0;
}

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

void init(graph &g, int v)
{
	g.v = v;
	g.adj = new list* [g.v];
	for (int i = 0; i < g.v; i++)
		g.adj[i] = 0;
}

void destruct(graph &g)
{
	for (int i = 0; i < g.v; i++)
		erase(g.adj[i]);
	delete [] g.adj;
}

void add_edge(graph &g, int v, int w)
{
	insert(g.adj[v], w);
	insert(g.adj[w], v);
}

void show(graph &g)
{
	for (int v = 0; v < g.v; v++)
	{
		list *a = adj(g, v);
		cout << v << " -";
		while (a)
		{
			cout << " " << a->key;
			a = a->next;
		}
		cout << endl;
	}
}

list *adj(graph &g, int v)
{
	return g.adj[v];
}

void dfs(graph &g, int v, bool *marked, bool *path, int i, int &n)
{
	if (i == n)
		path[v] = true;
	else
	{
		marked[v] = true;
		list *a = adj(g,v);
		while (a)
		{
			if (!marked[a->key])
			{
				dfs(g, a->key, marked, path, i + 1, n);
				marked[a->key] = false;
			}
			a = a->next;
		}
	}
}