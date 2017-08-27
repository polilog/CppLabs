#include <iostream>
#include <iomanip>

using namespace std;

template <class T = int>
class Matrix
{
private:
	int name;
	int nrow;
	int ncol;
	T **mat;
	static int count;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix &);
	~Matrix();
	bool check_square();
	Matrix operator +(const Matrix &);
	Matrix operator +=(const Matrix &);
	Matrix operator *(const Matrix &);
	Matrix operator *=(const Matrix &);
	Matrix operator =(const Matrix &);
	template <class T>
	friend istream & operator >>(istream &, Matrix <T> &);
	template <class T>
	friend ostream & operator <<(ostream &, Matrix <T> &);
};

template <class T>
int Matrix <T>::count = 0;

template <class T>
Matrix <T>::Matrix() : nrow(0), ncol(0), name(count)
{
	mat = NULL;
	count++;
}

template <class T>
Matrix <T>::Matrix(int m, int n)
{
	name = count;
	count++;
	nrow = m;
	ncol = n;
	mat = new T* [nrow];
	for (int i = 0; i < n; i++)
		mat[i] = new T [ncol];
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++)
			mat[i][j] = 0;
}

template <class T>
Matrix <T>::Matrix(const Matrix <T> &p)
{
	name = count;
	count++;
	nrow = p.nrow;
	ncol = p.ncol;
	mat = new T* [nrow];
	for (int i = 0; i < nrow; i++)
		mat[i] = new T [ncol];
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++)
			mat[i][j] = p.mat[i][j];
}

template <class T>
Matrix <T>::~Matrix()
{
	for (int i = 0; i < nrow; i++)
		delete [] mat[i];
	delete [] mat;
}

template <class T>
bool Matrix <T>::check_square()
{
	if (nrow == ncol)
		return true;
	else
		return false;
}

template <class T>
Matrix <T> Matrix <T>::operator +(const Matrix <T> &r)
{
	count--;
	if (nrow == r.nrow && ncol == r.ncol)
	{
		Matrix <T> sum (nrow, ncol);
		for (int i = 0; i < nrow; i++)
			for (int j = 0; j < ncol; j++)
				sum.mat[i][j] = mat[i][j] + r.mat[i][j];
		return sum;
	}
	else
	{
		Matrix <T> sum;
		cout << "Error";
		return sum;
	}
}

template <class T>
Matrix <T> Matrix <T>::operator +=(const Matrix <T> &r)
{
	if (nrow == r.nrow && ncol == r.ncol)
	{
		for (int i = 0; i < nrow; i++)
			for (int j = 0; j < ncol; j++)
				mat[i]j[j] += r.mat[i][j];
	}
	else
		cout << "Error";
	return *this;
}

template <class T>
Matrix <T> Matrix <T>::operator *(const Matrix <T> &r)
{
	count--;
	if (ncol == r.nrow)
	{
		Matrix <T> prod (nrow, r.ncol);
		for (int i = 0; i < nrow; i++)
			for (int j = 0; j < r.ncol; j++)
			{
				prod.mat[i][j] = 0;
				for (int k = 0; k < ncol; k++)
					prod.mat[i][j] += mat[i][k] * r.mat[k][j];
			}
		return prod;
	}
	else
	{
		Matrix <T> prod;
		cout << "Error";
		return prod;
	}
}

template <class T>
Matrix <T> Matrix <T>::operator *=(const Matrix <T> &r)
{
	if (ncol == r.nrow)
	{
		T **temp = new T* [nrow];
		for (int i = 0; i < nrow; i++)
			temp[i] = new T [r.ncol];
		for (int i = 0; i < nrow; i++)
			for (int j = 0; j < r.ncol; j++)
			{
				temp[i][j] = 0;
				for (int k = 0; k < ncol; k++)
					temp[i][j] += mat[i][k] * r.mat[k][j];
			}
		for (int i = 0; i < nrow; i++)
			delete [] mat[i];
		delete [] mat;
		mat = temp;
		ncol = r.ncol;
	}
	else
		cout << "Error";
	return *this;
}

template <class T>
istream & operator >>(istream &in, Matrix <T> &r)
{
	cout << "Matrix " << r.name << endl;
	for (int i = 0; i < r.nrow; i++)
		for (int j = 0; j < r.ncol; j++)
			in >> r.mat[i][j];
	return in;
}

template <class T>
ostream & operator <<(ostream &out, Matrix <T> &r)
{
	out << "Matrix " << r.name << endl;
	for (int i = 0; i < r.nrow; i++)
	{
		for (int j = 0; j < r.ncol; j++)
			out << r.mat[i][j] << " ";
		out << endl;
	}
	out << endl;
	return out;
}

template <class T>
Matrix <T> Matrix <T>::operator =(const Matrix <T> &r)
{
	nrow = r.nrow;
	ncol = r.ncol;
	mat = r.mat;
	return *this;
}