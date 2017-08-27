#include "list.h"

class Graph
{
private:
	int v;
	list **adj;
public:
	Graph();
	Graph(int);
	Graph(Graph &);
	~Graph();
	void init(int);
	void destruct();
	void add_edge(int, int);
	void show();
	list *get_adj(int);
	void dfs(int, bool *, bool *, int, int &);
	friend void erase(list *&);
	friend void insert(list *&, int);
};