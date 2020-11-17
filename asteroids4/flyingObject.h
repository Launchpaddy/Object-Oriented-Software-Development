#ifndef flyingObject_h
#define flyingObject_h

#define OFF_SCREEN_BORDER_AMOUNT 5
#define PI 3.141592653589793

#include "point.h"
#include "velocity.h"

/*************************************
* BASE CLASS FLYING OBJECT
*************************************/
class FlyingObject
{
private:

	float x;
	float y;
	Point topLeft;
	Point bottomRight;

protected:
	Point point;
	Velocity vel;
	bool alive;

public:
	// Constructor
	FlyingObject();
	// Getters
	Point getPoint()       const { return point; }
	Velocity getVelocity() const { return vel; }
	float getDx()          const { return vel.getDx(); }
	float getDy()          const { return vel.getDy(); }
	float getX()           const { return point.getX(); }
	float getY()           const { return point.getY(); }
	bool isAlive()         const { return alive; }

	void addDx(float x)          { vel.setDx(vel.getDx() + x); }
	void addDy(float y)          { vel.setDy(vel.getDy() + y); }
	
	// Setters
	void setVelocity(Velocity vl)   { vel = vl; }
	void setPoint(Point pt)         { point = pt; }
	void setPoint(float x, float y) { point = Point(x, y); } // nice for starting points
	void setAlive(bool alive)       { this->alive = alive; }
	void setDx(float x)             { vel.setDx( x); }
	void setDy(float y)             { vel.setDy( y); }
	// Advance 
	void advance();
	void wrap();


};

#endif /* flyingObject_h */
