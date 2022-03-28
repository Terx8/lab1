#include "public_child.h"

#include <iostream>

void PUBqueue::myPush()
{
	Cparent::myPush();
}

PUBqueue* PUBqueue::myPop()
{
	return (PUBqueue*)Cparent::myPop();
}

void PUBqueue::max()
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