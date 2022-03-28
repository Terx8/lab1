#include "parent.h"
#include <iostream>

class PROqueue : public Cparent
{
public:
	void myPush();
	PROqueue* myPop();
	void max();

};
