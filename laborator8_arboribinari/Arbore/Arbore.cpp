#include <iostream>
#include "Arbore.h"

static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do  c = getchar();  while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}

static Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;
		rad->data = citesteNume();
		if (car != '(')
		{
			rad->stg = 0;
			rad->drt = 0;
		}
		else
		{
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',')
			{
				rad->drt = 0;
			}
			else
			{
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')')  eroare();
			car = readchar();
		}
	}
	return rad;
}

Nod* creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}
