#include <iostream>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

template <class T>
struct node
{
	T data;
	node <T> *left;
	node <T> *right;
};

template <class T = int>
class Tree
{
private:
	node <T> *root;

	void clear(node <T> *);
	void copy(node <T> *);
	void insert(node <T> *&, T);
	void init(node <T> *&, T);
	node <T> *find(node <T> *, T);
	void printlevel(int, ostream &, node <T> *);
	void tree_depth(node <T> *, int &);
	void preorder(node <T> *&, int *, int);
public:
	Tree();
	Tree(int);
	Tree(const Tree &);
	~Tree();
	void copy(const Tree &);
	void clear();
	void clear(T);
	void insert(T);
	node <T> *find(T);
	template <class T>
	friend ostream & operator <<(ostream &, Tree <T> &);
	void preorder(int *, int);
	int tree_depth();
};

template <class T>
Tree <T>::Tree() 
{
	top = NULL;
}

template <class T>
Tree <T>::Tree(int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		T key = rand() % 100;
		insert(key);
		cout << key << " ";
	}
	cout << endl;
}

template <class T>
void Tree <T>::init(node <T> *&top, T key)
{
	top = new node <T>;
	top->data = key;
	top->left = NULL;
	top->right = NULL;
}

template <class T>
Tree <T>::Tree(const Tree &t)
{
	copy(t.root);
}

template <class T>
void Tree <T>::copy(const Tree <T> &t)
{
	copy(t.root);
}

template <class T>
void Tree <T>::copy(node <T> *top)
{
	if (top != NULL)
	{
		insert(top->data);
		copy(top->left);
		copy(top->right);
	}
}

template <class T>
Tree <T>::~Tree()
{
	clear(root);
}

template <class T>
void Tree <T>::clear(node <T> *top)
{
	if (top != NULL)
	{
		clear(top->left);
		clear(top->right);
		delete top;
	}
}

template <class T>
void Tree <T>::clear(T key)
{
	node <T> *temp = find(root, key);
	clear(temp);
}

template <class T>
void Tree <T>::clear()
{
	clear(root);
}

template <class T>
void Tree <T>::insert(node <T> *&top, T key)
{
	if (top == NULL)
		init(top, key);
	else
	{
		if (key > top->data)
			insert(top->right, key);
		else
			insert(top->left, key);
	}
}

template <class T>
void Tree <T>::insert(T key)
{
	insert(root, key);
}

template <class T>
node <T> Tree <T>::*find(node <T> *top, T key)
{
	if (top != NULL)
	{
		if (top->data == key)
			return top;
		if (key < top->data)
			find(top->left, key);
		else
			find(top->right, key);
	}
	else
		return NULL;
}

template <class T>
node <T> Tree <T>::*find(T key)
{
	return find(root, key);
}

template <class T>
ostream & operator <<(ostream &out, Tree <T> &t)
{
	t.printlevel(1, out, t.root);
	return out;
}

template <class T>
void Tree <T>::printlevel(int n, ostream &out, node <T> *top)
{
	if (top != NULL)
	{
		printlevel(n + 1, out, top->right);
		out << setw((n - 1) * 4) << " " << setw(4) << top->data << endl;
		printlevel(n + 1, out, top->left);
	}
}

template <class T>
void Tree <T>::tree_depth(node <T> *top, int &depth)
{
	if (top != NULL)
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

template <class T>
int Tree <T>::tree_depth()
{
	int depth;
	tree_depth(root, depth);
	return depth;
}

template <class T>
void Tree <T>::preorder(int *level, int i)
{
	preorder(root, level, 0);
}

template <class T>
void Tree <T>::preorder(node <T> *&top, int *level, int i)
{
	if (top != NULL)
	{
		level[i]++;
		preorder(top->left, level, i + 1);
		preorder(top->right, level, i + 1);
	}
}