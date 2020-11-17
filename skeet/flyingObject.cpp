#include "point.h"
#include "flyingObject.h"
#include "velocity.h"
#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.141592653589793

/*******************************************
* Constructor 
*********************************************/
FlyingObject::FlyingObject()
{

	point = Point(0,0);
	vel = Velocity();
	
	alive = true;
}

/*******************************************
*	Addvances any object under the base class (birds/ bullets)
*********************************************/
void FlyingObject::advance()
{
	point.addX(vel.getDx());
	point.addY(vel.getDy());
}



