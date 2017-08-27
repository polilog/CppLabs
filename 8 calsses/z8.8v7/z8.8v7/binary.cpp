#include "stdafx.h"
#include "binary.h"
#include <string>
#include <cmath>

Binary::Binary() : len(1), sign(0)
{
	number.assign(size, 0);
}

Binary::Binary(const Binary &bin)
{
	len = bin.len;
	sign = bin.sign;
	number.assign(size, 0);
	for (int i = 0; i < len; i++)
		number[i] = bin.number[i];
}

void Binary::operator =(const Binary &bin)
{
	len = bin.len;
	sign = bin.sign;
	number.assign(size, 0);
	for (int i = 0; i < len; i++)
		number[i] = bin.number[i];
}

Binary::Binary(long data)
{
	LongToBinary (data);
}

Binary::Binary(const char *data)
{
	char *str = new char [strlen(data) + 1];
	strcpy(str, data);
	StringToBinary(str);
	delete [] str;
}

Binary::~Binary()
{}

long Binary::BinaryToLong()
{
	if (len <= 8 * sizeof(long))
	{
		long res = number[len - 1];
		for (int i = len - 1; i > 0; i--)
			res = res * 2 + number[i - 1];
		if (sign)
			return -res;
		else
			return res;
	}
	else
	{
		cout << "Error! Too long number!" << endl;
		return 0;
	}
}

void Binary::LongToBinary (long data)
{
	sign = (data < 0);
	data = abs(data);
	number.assign(size, 0);
	int i = 0;
	do
	{
		number[i] = data % 2;
		data /= 2;
		i++;
	}
	while (data > 0);
	len = i;
}

bool Binary::CheckString(char *data)
{
	int l = strlen(data);
	while (l > 0 && data[l - 1] == ' ')
		l--;
	if (l > size || l == 0)
		return false;
	data[l] = '\0';
	for (int i = 1; i < l; i++)
		if (data[i] != '1' && data[i] != '0')
			return false;
	if (data[0] != '1' && data[0] != '0' && data[0] != '+' && data[0] != '-')
		return false;
	return true;
}

void Binary::StringToBinary(char *str)
{
	number.assign(size, 0);
	if (CheckString(str))
	{
		int l = strlen(str);
		for (int i = 0; i < l - 1; i++)
			number[i] = str[l - 1 - i] - '0';
		if (str[0] == '-')
			sign = 1;
		else
		{
			sign = 0;
			if (str[0] == '1')
			{
				number[l - 1] = 1;
				l++;
			}
		}
		len = --l;
	}
	else
	{
		cout << "Error! Incorrect number!" << endl;
		len = 1;
		sign = 0;
		number.assign(size, 0);
	}
}

char *Binary::BinaryToString()
{
	char *str = new char [size + 2];
	int i;
	for (i = 0; i < len; i++)
		str[i] = number[i] + '0';
	if (sign)
	{
		str[i] = '-';
		str[++i] = '\0';
	}
	else
		str[i] = '\0';
	strrev(str);
	return str;
}

char Binary::operator [](int i)
{
	if (i >= 0 && i < len)
		return number[i];
	else
		return 0;
}

ostream & operator <<(ostream &out, Binary &b)
{
	if (b.sign)
		out << '-';
	for (int i = b.len - 1; i >= 0; i--)
		if (b.number[i])
			out << '1';
		else
			out << '0';
	out << endl;
	return out;
}

istream & operator >>(istream &in, Binary &b)
{
	char *str = new char [b.size + 1];
	in >> str;
	b.StringToBinary(str);
	delete [] str;
	return in;
}

Binary Binary::operator +(Binary &b)
{
	if (sign == b.sign)
	{
		Binary res;
		res.number.assign(size, 0);
		res.sign = sign;
		int l = (len > b.len) ? len : b.len;
		int carry = 0;
		for (int  i = 0; i < l; i++)
		{
			int d1 = (*this)[i];
			int d2 = b[i];
			int temp = d1 + d2 + carry;
			if (temp > 1)
			{
				carry = temp / 2;
				res.number[i] = temp % 2;
			}
			else
			{
				carry = 0;
				res.number[i] = temp;
			}
		}
		if (carry == 1 && l < size)
		{
			res.number[l] = 1;
			l++;
		}
		res.len = l;
		return res;
	}
	else
	{
		b.sign = !b.sign;
		Binary res = *this - b;
		b.sign = !b.sign;
		return res;
	}
}

Binary Binary::operator -(Binary &b)
{
	if (sign == b.sign)
	{
		if (len < b.len)
		{
			Binary res = b - *this;
			return res;
		}
		else
		{
			if (len == b.len && strcmp(BinaryToString(), b.BinaryToString()) < 0)
			{
				Binary res = b - *this;
				res.sign = !res.sign;
				return res;
			}
			else
			{
				Binary res;
				Binary temp = *this;
				res.sign = sign;
				res.number.assign(size, 0);
				for (int i = 0; i < len; i++)
				{
					if (temp[i] - b[i] < 0)
					{
						int j = i + 1;
						while (temp[j] == 0)
							j++;
						temp.number[j] = 0;
						for (int k = j - 1; k >= i; k--)
							temp.number[k] = 1;
						res.number[i] = temp[i] - b[i] + 1;
					}
					else
						res.number[i] = temp[i] - b[i];
				}
				if (res.number[len - 1] == 0)
					res.len = len - 1;
				else
					res.len = len;
				return res;
			}
		}
	}
	else
	{
		b.sign = !b.sign;
		Binary res = *this + b;
		b.sign = !b.sign;
		return res;
	}
}

Binary Binary::operator *(Binary &b)
{
	Binary res;
	if (len + b.len >= size)
		cout << "Warning! Too long numbers!" << endl;
	if (sign == b.sign)
		res.sign = 0;
	else
		res.sign = 1;
	for (int i = 0; i < b.len; i++)
	{
		if (b[i])
		{
			Binary temp = Shift(i);
			res = res + temp;
		}
	}
	return res;
}

Binary Binary::Shift(int i)
{
	Binary res;
	res.number.assign(size, 0);
	for (int j = i; j < len + i; j++)
		if (j < size)
			res.number[j] = number[j - i];
	res.sign = 0;
	res.len = (size < len + i) ? size : len + i;
	return res;
}