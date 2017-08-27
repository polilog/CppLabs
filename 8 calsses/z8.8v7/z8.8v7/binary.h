#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Binary
{
	static const int size = 128;
	int len;
	char sign;
	vector <bool> number;
public:
	Binary();
	Binary(const Binary &);
	Binary(long);
	Binary(const char *);
	~Binary();

	void LongToBinary(long);
	long BinaryToLong();
	Binary operator +(Binary &);
	Binary operator -(Binary &);
	Binary operator *(Binary &);
	void operator =(const Binary &);
	char operator [](int);
	friend ostream & operator <<(ostream &, Binary &);
	friend istream & operator >>(istream &, Binary &);
	
private:
	bool CheckString(char *);
	char *BinaryToString();
	void StringToBinary(char *);
	Binary Shift(int);

	//char *ToComplCode();
	//Binary FromComplCode(char *);
	//friend char *Sum(char *, char *);
};