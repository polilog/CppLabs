#include "stdafx.h"
#include "complex.h"
#include <cmath>

Complex::Complex() : abs(0), arg(0)
{}

Complex::Complex(double _abs, double _arg)
{
	abs = _abs;
	set_arg(_arg);
}

Complex::Complex(double _abs)
{
	abs = _abs;
	arg = 0;
}

Complex::Complex(const Complex &c)
{
	abs = c.abs;
	arg = c.arg;
}

Complex::~Complex()
{}

Complex Complex::power(int n)
{
	Complex res;
	res.abs = pow(abs, n);
	res.set_arg(n * arg);
	return res;
}

Complex Complex::sqr()
{
	Complex res;
	res.abs = sqrt(abs);
	res.arg = arg / 2;
	return res;
}

Complex & Complex::operator =(const Complex &c)
{
	abs = c.abs;
	arg = c.arg;
	return *this;
}

Complex Complex::operator +(const Complex &c)
{
	Complex res;
	res.abs = sqrt(abs * abs + c.abs * c.abs + 2 * abs * c.abs * cos(arg - c.arg));
	double x = abs * cos(arg) + c.abs * cos(c.arg);
	double y = abs * sin(arg) + c.abs * sin(c.arg);
	if (x > 0)
		res.arg = atan(y / x);
	else
		if (y > 0)
			res.arg = pi + atan(y / x);
		else
			res.arg = atan(y / x) - pi;
	return res;
}

Complex Complex::operator +=(const Complex &c)
{
	Complex res;
	res.abs = sqrt(abs * abs + c.abs * c.abs + 2 * abs * c.abs * cos(arg - c.arg));
	double x = abs * cos(arg) + c.abs * cos(c.arg);
	double y = abs * sin(arg) + c.abs * sin(c.arg);
	if (x > 0)
		res.arg = atan(y / x);
	else
		if (y > 0)
			res.arg = pi - atan(y / x);
		else
			res.arg = atan(y / x) - pi;
	*this = res;
	return *this;
}

Complex Complex::operator *(const Complex &c)
{
	Complex res;
	res.abs = abs * c.abs;
	res.set_arg(arg + c.arg);
	return res;
}

Complex Complex::operator *=(const Complex &c)
{
	abs *= c.abs;
	set_arg(arg + c.arg);
	return *this;
}

void Complex::set_arg(double a)
{
	arg = a;
	if (arg > 0)
		while (arg > pi)
			arg -= pi;
	else
		while (arg < -pi)
			arg += pi;
}

istream & operator >>(istream &in, Complex &c)
{
	cout << "abs = ";
	in >> c.abs;
	cout << "arg = ";
	in >> c.arg;
	cout << endl;
	return in;
}

ostream & operator <<(ostream &out, Complex &c)
{
	out << "abs = " << c.abs << endl;
	out << "arg = " << c.arg << endl;
	out << endl;
	return out;
}