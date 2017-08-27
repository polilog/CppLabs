#include <iostream>
#include <clocale>

using namespace std;

template <class T>
struct node
{
	T data;
	node *next;
	node *prev;
};

template <class T = int>
class DList 
{
private:
	node <T> *top;
	node <T> *end;
	int size;
public:
	DList();
	DList(int);
	DList(const DList &);
	~DList();
	void push_back(T);
	void erase(int);
	int find(T) const;
	template <class T>
	friend ostream & operator <<(ostream &, DList <T> &);
	void clear();
	T calc() const;
private:
	void init(T);
};

template <class T>
DList <T>::DList() : size(0)
{
	top = NULL;
	end = NULL;
}

template <class T>
DList <T>::DList(int n)
{
	T x;
	size = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		push_back(x);
	}
}

template <class T>
DList <T>::DList(const DList &p)
{
	size = 0;
	node <T> *temp = p.top;
	while (temp)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

template <class T>
DList <T>::~DList()
{
	clear();
}

template <class T>
void DList <T>::init(T x)
{
	top = new node <T>;
	end = top;
	top->data = x;
	top->next = NULL;
	top->prev = NULL;
	size++;
}

template <class T>
void DList <T>::push_back(T x)
{
	if (size == 0)
		init(x);
	else
	{
		node <T> *temp = new node <T>;
		temp->data = x;
		temp->next = NULL;
		temp->prev = end;
		end->next = temp;
		end = end->next;
		size++;
	}
}

template <class T>
void DList <T>::erase(int pos)
{
	if (pos < size)
	{
		node <T> *nv = top;
		for (int i = 0; i < pos; i++)
			nv = nv->next;
		node <T> *pv = nv->prev, *ppv = nv->next;
		if (pv)
			pv->next = ppv;
		else
			ppv = top;
		if (ppv)
			ppv->prev = pv;
		else
			pv = end;
		delete nv;
		size--;
	}
}

template <class T>
int DList <T>::find(T key) const
{
	node <T> *temp = top;
	for (int i = 0; i < size; i++)
	{
		if (temp->data == key)
			return i;
		temp = temp->next;
	}
	return -1;
}

template <class T>
void DList <T>::clear()
{
	node <T> *temp = top;
	while (temp)
	{
		temp = temp->next;
		delete top;
		top = temp;
	}
	end = NULL;
}

template <class T>
ostream & operator <<(ostream &out, DList <T> &p)
{
	node <T> *temp = p.top;
	while (temp)
	{
		out << temp->data << " ";
		temp = temp->next;
	}
	out << endl;
	return out;
}

template <class T>
T DList <T>::calc() const
{
	if (size % 2 == 0)
	{
		node <T> *first = top, *last = end;
		T result = 1;
		for (int i = 0; i < size / 2; i++)
		{
			result += first->data * last->data;
			first = first->next;
			last = last->prev;
		}
		return result;
	}
	else
	{
		cout << "Число элементов в списке должно быть четным" << endl;
		return 0;
	}
}