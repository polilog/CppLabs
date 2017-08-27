// z9.3v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "university.h"
#include "lyceum.h"
#include "school.h"
#include "college.h"
#include "institute.h"
#include "academy.h"
#include "list.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	University u("BSU", 5000, 15);
	Lyceum l("BSU Lyceum", 500, 2);
	School s("#1", 600, "Grodno");
	College c("Trinity College", 1000, 40);
	Academy a("Gorky Academy", 3000, false);
	Institute i("Moscow Institute of Physics and Technology", 10000, 500);

	List <Establishment *> lst;
	lst.push_back(&u);
	lst.push_back(&l);
	lst.push_back(&s);
	lst.push_back(&c);
	lst.push_back(&a);
	lst.push_back(&i);

	lst.print();
	return 0;
}

