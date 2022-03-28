#include "protected_child.h"

#include <iostream>

void PROqueue::myPush()
{
	Cparent::myPush();
}

PROqueue* PROqueue::myPop()
{
	return (PROqueue*)Cparent::myPop();
}

void PROqueue::max()
{
	nodep parent = gethead()->next;
	int max = parent->value;
	while (parent != NULL)
	{
		if (parent->value > max)
		{
			max = parent->value;
		}
		parent = parent->next;
	}

	printf("maximun value is %d\n", max);
}
