#include "stdafx.h"
#include "binary.h"
#include <string>
#include <cmath>

Binary::Binary()
{
	for (int i = 0; i < len; i++)
		number[i] = 0;
	for (int i = 0; i < len; i++)
		compl[i] = 0;
	sign = 0;
}

Binary::Binary(const Binary &bin)
{
	strcpy(number, bin.number);
	strcpy(compl, bin.compl);
	sign = bin.sign;
}

Binary::Binary(long data)
{
	LongToBinary (data);
	ToComplCode();
}

Binary::Binary(const char *data)
{
	sign = 0;
	char* dt = new char[strlen(data) + 1];
	strcpy (dt, data);
	if (!CheckString(dt))
	{
		for (int i = 0; i < len; i++)
			number[i] = 0;
		for (int i = 0; i < len; i++)
			compl[i] = 0;
	}
	else
	{
		BinaryFromString(dt);
		ToComplCode();
	}
}

long Binary::BinaryToLong()
{
	long res = number[0];
	for (int i = 1; i < len; i++)
		res = res * 2 + number[i];
	return res;
}

void Binary::LongToBinary (long data)
{
	int i = 1;
	sign = (data < 0);
	data = abs(data);
	for (int i = 0; i < len; i++)
		number[i] = 0;
	while (data > 1)
	{
		number[len - i] = data % 2;
		data /= 2;
		i++;
	}
	number[len - i] = data;
}

void Binary::BinaryFromString (char* in)
{
	for (int i = 0; i < len; i++)
		number[i] = 0;
	int l = strlen (in);
	for (int i = l - 1, j = 1; i > 0; i--, j++)
		number[len - j] = in[i] - 48;
	if (in[0] == '-')
		sign = 1;
	else
		if (in[0] == '+')
			sign = 0;
		else
		{
			sign = 0;
			number[len - l] = in[0] - 48;
		}
}

bool Binary::CheckString(char *data)
{
	int l = strlen(data);
	while (l > 0 && data[l - 1] == ' ')
		l--;
	if (l > len - 1 || l == 0)
		return false;
	
	data[l] = '\0';

	for (int i = 0; i < l; i++)
		if (data[i] != '1' && data[i] != '0')
			return false;
	return true;
}

void Binary::ToComplCode()
{
	if (!sign)
		strcpy (compl, number);
	else
	{
		int l = GetCount();
		for (int i = 0; i < len; i++)
			compl[i] = 0;
		for (int i = len - 1, j = 0; i >= 0 && j < l; i--, j++)
			compl[i] = !number[i];
		char one [len], res[len];
		for (int i = 0; i < len; i++)
			one[i] = 0;
		one[len - 1] = 1;
		Summ(compl, one, res);
		strcpy(compl, res);
		compl[len - l - 1] = 1;
	}
}

void Binary::FromComplCode()
{
	for (int i = 0; i = len; i++)
		number[i] = 0;
	int count = GetCount();
	sign = compl[len - count - 1];
	if (!sign)
	{
		for (int i = len - 1, j = 0; i >= 0 && j < count; i--, j++)
			number[i] = compl[i];
		return;
	}
	for (int i = len - 1, j = 0; i >= 0 && j < count; i--, j++)
		number[i] = !compl[i];
	char one [len], res[len];
	for (int i = 0; i < len; i++)
		one[i] = 0;
	one[len - 1] = 1;
	Summ (number, one, res);
	strcpy (number, res);
}

void Binary::Summ(char *str1, char *str2, char *res)
{
	char one = 0, tmp;
	for (int i = 0; i < len; i++)
		res[i] = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		tmp = str1[i]+str2[i] + one;
		if (tmp > 1)
		{
			one = 1;
			res[i] = tmp % 2;
		}
		else
		{
			one = 0;
			res[i] = tmp;
		}
	}
	if (one != 0)
		cout << "Very big summ!" << endl; 
}

int Binary::GetCount()
{
	int i = 0;
	while (i < len && number[i] == 0)
		i++;
	return len - i;
}

Binary Binary::operator +(Binary &b)
{
	char res[len];
	Binary bin;
	Summ(compl, b.compl, res);
	strcpy(bin.compl, res);
	bin.FromComplCode();
	return bin;
}

ostream& operator <<(ostream &str, Binary &b)
{
	char buf[b.len + 2];
	b.ToString(buf);
	str << buf;
	return str;
}

istream& operator >>(istream &str, Binary &b)
{
	char buf[b.len + 2];
	str >> buf;
	Binary t (buf);
	b = t;
	return str;
}

void Binary::ToString(char *str)
{
	int i = 0, j = 0;
	while (i < len && number[i] == 0)
		i++;
	if (sign)
	{
		str[j]='-';
		j++;
	}
	for (; i < len; i++, j++)
		str[j] = number[i] ? '1' : '0';
	if (j == 0)
	{
		str[j] = '0';
		j++;
	}
	str[j] = '\0';
}