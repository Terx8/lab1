#include "parent.h"
#include <iostream>

class PUBqueue : public Cparent
{
public:
	void myPush();
	PUBqueue* myPop();
	void max();

};
