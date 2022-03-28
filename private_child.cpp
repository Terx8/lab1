#include "private_child.h"

#include <iostream>

void PRIqueue::myPush()
{
	Cparent::myPush();
}

PRIqueue* PRIqueue::myPop()
{
	return (PRIqueue*)Cparent::myPop();
}

void PRIqueue::max()
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
