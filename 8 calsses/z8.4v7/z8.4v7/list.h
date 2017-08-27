#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

template <class T>
struct element
{
	T data;
	element *next;
};

template <class T = int>
class List
{
private:
	element <T> *top;
	element <T> *end;

	void init(T);
	element <T> *find (T);
public:
	List();
	List(int n);
	List(List &);
	~List();
	void push_back(T);
	void pop_front();
	void clear();
	int find_pos(T);
	template <class T>
	friend ostream & operator <<(ostream &, List <T> &);
	void difference(List &, List &);
	void merge(List &, List &);
};

template <class T>
List <T>::List()
{
	top = NULL;
	end = NULL;
}

template <class T>
List <T>::List(int n)
{
	T x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		push_back(x);
	}
}

template <class T>
List <T>::List(List <T> &p)
{
	clear();
	element <T> *temp = p.top;
	while (temp != NULL)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

template <class T>
List <T>::~List()
{
	clear();
}

template <class T>
int List <T>::find_pos(T key)
{
	int i = 0;
	element <T> *temp = top;
	while (temp != NULL)
	{
		if (temp->data == key)
			return i;
		i++;
		temp = temp->next;
	}
	return -1;
}

template <class T>
ostream & operator <<(ostream &out, List <T> &p)
{
	element <T> *temp = p.top;
	while (temp != NULL)
	{
		out << temp->data << " ";
		temp = temp->next;
	}
	out << endl;
	return out;
}

template <class T>
void List <T>::clear()
{
	while (top != NULL)
		pop_front();
}

template <class T>
void List <T>::init(T key)
{
		top = new element <T>;
		top->data = key;
		top->next = NULL;
		end = top;
}

template <class T>
void List <T>::push_back(T key)
{
	if (top == NULL)
		init(key);
	else
	{
		element <T> *temp = new element <T>;
		temp->data = key;
		temp->next = NULL;
		end->next = temp;
		end = end->next;
	}
}

template <class T>
void List <T>::pop_front()
{
	if (top != NULL)
	{
		element <T> *temp = top;
		if (top == end)
			end = NULL;
		top = top->next;
		delete temp;
	}
}

template <class T>
element <T> * List <T>::find(T key)
{
	element <T> *pos = top;
	while (pos != NULL && pos->data != key)
			pos = pos->next;
	return pos;
}

template <class T>
void List <T>::difference(List <T> &first, List <T> &second)
{
	element <T> *temp = first.top;
	while (temp != NULL)
	{
		if (second.find_pos(temp->data) == -1)
		{
			if (find_pos(temp->data) == -1)
				push_back(temp->data);
		}
		temp = temp->next;
	}
}

template <class T>
void List <T>::merge(List <T> &first, List <T> &second)
{
	clear();
	difference(first, second);
	difference(second, first);
}