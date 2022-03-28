#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct Tnode
{
	int value;
	struct Tnode* next;

} node, * nodep;

class Cparent
{
private:
	nodep head;
	nodep last;

protected:
	void push(int val);
	Cparent* pop();
	
public:
	Cparent();
	Cparent(Cparent* basa); // copy
	Cparent(Cparent* first, Cparent* second); // merg

	void print();
	void myPush();
	Cparent* myPop();

	nodep gethead() { return head; };
};

