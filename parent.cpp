#include "parent.h"

#include <iostream>

Cparent::Cparent()
{
	nodep _head = new node;
	if (_head == NULL) exit(-1);

	head = _head; 

	head->value = 0;
	head->next = NULL;

	last = head;
}

Cparent::Cparent(Cparent* basa)
{
	Cparent* cpy = this;

	nodep _head = new node;
	if (_head == NULL) exit(-1);

	head = _head;

	head->value = 0;
	head->next = NULL;

	last = head;

	nodep cNode = basa->head->next;
	while (cNode != NULL)
	{
		cpy->push(cNode->value);
		cNode = cNode->next;
	}

}

Cparent::Cparent(Cparent* first, Cparent* second) // merg
{
	Cparent* merg = this;
	nodep _head = new node;
	if (_head == NULL) exit(-1);

	head = _head;

	head->value = 0;
	head->next = NULL;

	last = head;
	nodep cNode = first->head->next;
	while (cNode != NULL)
	{
		merg->push(cNode->value);
		cNode = cNode->next;
	}
	
	cNode = second->head->next;

	while (cNode != NULL)
	{
		merg->push(cNode->value);
		cNode = cNode->next;
	}

}


void Cparent::push(int val) 
{
	nodep _node = new node;
	if (_node == NULL) exit(-1);

	_node->value = val;
	_node->next = NULL;

	last->next = _node;
	last = _node;
}

Cparent* Cparent::pop() 
{
	nodep prev = head->next;
	if (head->next == NULL)
	{
		printf("queue is empty\n");
		return this;
	}

	head->next = prev->next;
	delete prev;

	if (head->next == NULL)
	{
		printf("queue is empty, exiting programm\n");
		return NULL;
	}
	return this;
}

void Cparent::print()
{
	nodep current = head->next;
	if (head->next == NULL)
		printf("queue is empty\n");

	while (current != NULL)
	{
		printf(" (%d) ", current->value);

		current = current->next;
	}
	printf("\n");

}

Cparent* Cparent::myPop()
{
	return pop();
}

void Cparent::myPush()
{
	int val;
	while (1) 
	{
		if (scanf("%d", &val) == 0) printf("invalid input\n");
		else break;
		getchar();
	}
	push(val);
}
