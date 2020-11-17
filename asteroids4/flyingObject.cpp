#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#include "game.h"



/*******************************************
* Constructor
*********************************************/
FlyingObject::FlyingObject()
{
	topLeft = Point(START_POSITIONS_MAX, END_POSITION_MAX);
	bottomRight = Point(END_POSITION_MAX, START_POSITIONS_MAX);

	point = Point(0, 0);
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
	wrap();
}

/*********************************************
* Wraps every object to the other side of the screen
**********************************************/
void FlyingObject::wrap()
{

	if (point.getX() <= topLeft.getX())
	{
		point.setX(WRAP_DISTANCE);
	}

	if (point.getX() >= bottomRight.getX())
	{
		point.setX(-WRAP_DISTANCE);
	}

	if (point.getY() >= topLeft.getY())
	{
		point.setY(-WRAP_DISTANCE);
	}

	if (point.getY() <= bottomRight.getY())
	{
		point.setY(WRAP_DISTANCE);
	}
	
}

