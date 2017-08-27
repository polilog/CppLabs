// z7.5v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct tree
{
	int data;
	tree *left;
	tree *right;
};

void push(int, tree *&);
void print_tree_level(tree *, int);
void preorder(tree *, int *, int);
void delete_tree(tree *&);
void tree_depth (tree *, int &);


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int n;
	cout << "n = ";
	cin >> n;

	tree *t = NULL;
	for (int i = 0; i < n; i++)
	{
		int temp;
		temp = rand() % 51;
		cout << temp << " ";
		push(temp, t);
	}
	cout << endl;
	print_tree_level(t, 0);
	//можно сделать за один проход, используя список, а не находя глубину
	int depth;
	tree_depth(t, depth);
	int *level = new int [depth];
	for(int i = 0; i < depth; i++)
		level[i] = 0;
	preorder(t, level, 0);
	int max = 0;
	for (int i = 0; i < depth; i++)
		if (level[i] > level[max])
			max = i;
	cout << "max = " << max + 1  << " " << endl;
	delete_tree(t);
	delete [] level;
	return 0;
}

void push(int d, tree *&t)
{
	if (t == NULL)
	{
		t = new tree;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		return;
	}
	if (d > t->data)
		push(d, t->right);
	else
		push(d, t->left);
}

void print_tree_level(tree *top, int level)
{
	if (top)
	{
		print_tree_level(top->left, level + 1);
		for (int i = 0; i < level; i++)
			cout << "	";
		cout << setw(3) << top->data << endl;
		print_tree_level(top->right, level + 1);
	}
}

void tree_depth(tree *top, int &depth)
{
	if (top)
	{
		int r, l;
		tree_depth(top->left, l);
		tree_depth(top->right, r);
		if (l < r)
			depth = r + 1;
		else
			depth = l + 1;
	}
	else
		depth = 0;
}

void preorder(tree* top, int *level, int i)
{
	if (top)
	{
		level[i]++;
		preorder(top->left, level, i + 1);
		preorder(top->right, level, i + 1);
	}
}

void delete_tree(tree *&top)
{
	if (top)
	{
		delete_tree(top->left);
		delete_tree(top->right);
		delete top;
		top = NULL;
	}
}