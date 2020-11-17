#ifndef BULLET_H
#define BULLET_H 
#include "flyingObject.h"
#include "velocity.h"
#include "point.h"




class Bullet : public FlyingObject
{
private:
	
	float angle;
	bool killed;
public:
	Bullet();
	float getAngle() const { return angle; }
	
	void fire(Point p, float angle);
	void kill() // killed a bird and now set to delete
	{
		alive = false;
	 	killed = true; 
	}
	void draw();
	
	
};
#endif