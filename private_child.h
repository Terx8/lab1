#include "parent.h"
#include <iostream>

class PRIqueue : public Cparent
{
public:
	void myPush();
	PRIqueue* myPop();
	void max();

};
