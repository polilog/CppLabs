#include <iostream>


using namespace std;

const double pi = acos(-1);

class Complex
{
private:
	double abs;
	double arg;
public:
	Complex();
	Complex(double, double);
	Complex(double);
	Complex(const Complex &);
	~Complex();

	Complex power(int);
	Complex sqr();
	Complex & operator =(const Complex &);
	Complex operator +(const Complex &);
	Complex operator +=(const Complex &);
	Complex operator *(const Complex &);
	Complex operator *=(const Complex &);
	friend istream & operator >>(istream &, Complex &);
	friend ostream & operator <<(ostream &, Complex &);
private:
	void set_arg(double);
};