#include "stdafx.h"
#include "graph.h"

Graph::Graph() : v(0)
{
	adj = NULL;
}

Graph::Graph(int n)
{
	init(n);
}

Graph::Graph(Graph &g)
{
	v = g.v;
	adj = new list* [v];
	for (int i = 0; i < v; i++)
	{
		list *temp = g.adj[i];
		while (temp)
		{
			insert(adj[i], temp->key);
			temp = temp->next;
		}
	}
}

Graph::~Graph()
{
	destruct();
}

void Graph::init(int n)
{
	v = n;
	adj = new list* [v];
	for (int i = 0; i < v; i++)
		adj[i] = 0;
}

void Graph::destruct()
{
	for (int i = 0; i < v; i++)
		erase(adj[i]);
	delete [] adj;
}

void Graph::add_edge(int v, int w)
{
	insert(adj[v], w);
	insert(adj[w], v);
}

void Graph::show()
{
	for (int i = 0; i < v; i++)
	{
		list *a = get_adj(i);
		cout << i << " -";
		while (a)
		{
			cout << " " << a->key;
			a = a->next;
		}
		cout << endl;
	}
}

list *Graph::get_adj(int v)
{
	return adj[v];
}

void Graph::dfs(int v, bool *marked, bool *path, int i, int &n)
{
	if (i == n)
		path[v] = true;
	else
	{
		marked[v] = true;
		list *a = get_adj(v);
		while (a)
		{
			if (!marked[a->key])
			{
				dfs(a->key, marked, path, i + 1, n);
				marked[a->key] = false;
			}
			a = a->next;
		}
	}
}