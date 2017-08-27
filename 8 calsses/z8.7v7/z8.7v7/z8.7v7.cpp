// z8.7v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "graph.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("data.txt");
	int V, E;
	fin >> V >> E;

	Graph g;
	g.init(V);

	for (int i = 0; i < E; i++)
	{
		int v, w;
		fin >> v >> w;
		g.add_edge(v, w);
	}

	g.show();

	int n, start;
	cout << "n = ";
	cin >> n;
	cout << "start = ";
	cin >> start;
	bool *marked = new bool [V];
	for (int i = 0; i < V; i++)
		marked[i] = false;
	bool *path = new bool [V];
	for (int i = 0; i < V; i++)
		path[i] = false;

	g.dfs(start, marked, path, 0, n);
	for (int i = 0; i < V; i++)
		if (path[i])
			cout << i << " ";
	cout << endl;

	delete [] marked;
	delete [] path;

	return 0;
}





