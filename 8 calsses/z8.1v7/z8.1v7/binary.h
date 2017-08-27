#pragma once
#include <iostream>

using namespace std;

class Binary
{
	static const int len = 128;
	char number[len];
	char compl [len]; //дополнительный код
	char sign;
public:
	Binary();
	Binary(const Binary &);
	Binary(long);
	Binary(const char *);

	Binary operator +(Binary &b2);
	friend ostream & operator <<(ostream &, Binary &);
	friend istream & operator >>(istream &, Binary &);
private:
	void LongToBinary(long);
	void BinaryFromString (char *);
	void ToComplCode();
	int GetCount();
	long BinaryToLong();
	bool CheckString(char *);
	void FromComplCode();
	void Summ(char *, char *, char *);
	void ToString(char *);
};