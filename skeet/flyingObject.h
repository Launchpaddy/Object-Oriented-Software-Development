#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H
#include "point.h"
#include "velocity.h"

class FlyingObject
{
private:
	
	bool isOnScreen;
	float x;  
	float y;  
	
	

protected:
	Point point;
	Velocity vel;
	bool alive;
	
	
public:
	FlyingObject();
	// Getters
	float getX() const { return point.getX(); }
	float getY() const { return point.getY(); }
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return vel; } 

	bool isAlive() { return alive; }
	// Setters
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setVelocity(Velocity vl) { vel = vl; }
	void setPoint(Point pt) { point = pt; }
	void setPoint(float x, float y) { point = Point(x,y);} // nice for starting points
	void setAlive(bool alive) { this->alive = alive; }
	
	// Advance 
	void advance();
	
	
	
};














#endif