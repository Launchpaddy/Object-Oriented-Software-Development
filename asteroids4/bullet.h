#ifndef bullet_h
#define bullet_h

#define BULLET_LIFE 40

#include "flyingObject.h"
#include "velocity.h"
#include "point.h"



/*************************************
* Bullet Class
**************************************/
class Bullet : public FlyingObject
{
private:
	int timer;
	float angle;
	bool killed;
public:
	Bullet();
	float getAngle() const { return angle; }

	void fire(Point p, float angle, Velocity vel);

	void kill() 
	{
		alive = false;
		killed = true;
	}
	void draw();


};



#endif /* bullet_h */
