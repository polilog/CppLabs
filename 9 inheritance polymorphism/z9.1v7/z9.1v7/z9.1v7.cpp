// z9.1v7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "university.h"
#include "lyceum.h"
#include "school.h"
#include "college.h"
#include "institute.h"
#include "academy.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	University u("BSU", 5000, 15);
	Lyceum l("BSU Lyceum", 500, 2);
	School s("#1", 600, "Grodno");
	College c("Trinity College", 1000, 40);
	Academy a("Gorky Academy", 3000, false);
	Institute i("Moscow Institute of Physics and Technology", 10000, 500);

	u.print_info();
	l.print_info();
	s.print_info();
	c.print_info();
	a.print_info();
	i.print_info();

	return 0;
}

