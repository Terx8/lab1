#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "public_child.h"
#include "protected_child.h"
#include "private_child.h"

int menu()
{
	int type = 0;
	printf("1 - pub 2 - protect 3 - priv\n");

	while (1)
	{
		if (scanf("%d", &type) == 0 || type < 1 || type >3)
			printf("invalid input, try again\n");
		else break;

		getchar();
	}

	PUBqueue* basaPUB = new PUBqueue;
	PROqueue* basaPRO = new PROqueue;
	PRIqueue* basaPRI = new PRIqueue;

	Cparent* copy = NULL;

	printf("\n-1 - exit \n1 - show all \n2 - show current \n3 - push \n4 - pop \n5 - max \n6 - copy \n7 - emerge \n\n");
	int take = 0;
	while (!take)
	{
		while (1)
		{
			if (scanf("%d", &take) == 0)
				printf("invalid input!\n");
			else
				break;
			getchar();
		}

		switch (take)
		{
		case -1: return 0;

		case 1: // показать все очереди
			if (type == 1)
			{
				basaPUB->print();
				if (copy != NULL)
					copy->print(); break;
			}
			if (type == 2)
			{
				basaPRO->print();
				if (copy != NULL)
					copy->print(); break;
			}
			if (type == 3)
			{
				basaPRI->print();
				if (copy != NULL)
					copy->print(); break;
			}

		case 2: // показать текущую очередь
			if (type == 1)
				basaPUB->print(); 
			
			if (type == 2)
				basaPRO->print(); 

			if (type == 3)
				basaPRI->print();
			
			break;

		case  3: // добавить элемент		
			if (type == 1)
				basaPUB->myPush(); 
			
			if (type == 2)
				basaPRO->myPush(); 

			if (type == 3)
				basaPRI->myPush();
			
			break;

		case 4: //удалить элемент
			if (type == 1)
			{
				if (basaPUB->myPop() == NULL)
					return 0;
				else
					break;
			}

			if (type == 2)
			{
				if (basaPRO->myPop() == NULL)
					return 0;
				else
					break;
			}
			if (type == 3)
			{
				if (basaPRI->myPop() == NULL)
					return 0;
				else
					break;
			}

		case 5: // найти максимальное значение
			if (type == 1)
				basaPUB->max();

			if (type == 2)
				basaPRO->max();
			
			if (type == 3)
				basaPRI->max();
				
			break;

		case 6:// копировать очередь
			if (copy != NULL)
				delete copy;

			if (type == 1)
				copy = new Cparent(basaPUB); 
			
			if (type == 2)
				copy = new Cparent(basaPRO); 

			if (type == 3)
				copy = new Cparent(basaPRI); 

			break;

		case 7:// соединить очереди
			if (type == 1)
			{
				if (basaPUB == NULL || copy == NULL)
				{
					printf("try again\n");
					break;
				}
				basaPUB =(PUBqueue*) new Cparent(basaPUB, copy);
			}
			if (type == 2)
			{
				if (basaPRO == NULL || copy == NULL)
				{
					printf("try again\n");
					break;
				}
				basaPRO = (PROqueue*) new Cparent(basaPRO, copy);
			}

			if (type == 3)
			{
				if (basaPRI == NULL || copy == NULL)
				{
					printf("try again\n");
					break;
				}
				basaPRI = (PRIqueue*) new Cparent(basaPRI, copy);
			}

			delete copy;
			copy = NULL;

			break;

		default: printf("unknown command, try again\n"); break;

		}

		take = 0;
	}

	return 0;
}

int main()
{
	menu();
	return 0;
}