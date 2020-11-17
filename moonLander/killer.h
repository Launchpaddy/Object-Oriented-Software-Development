#ifndef KILLER_H
#define KILLER_H
#include "lander.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include <cmath>


class Killer 
{

private:
	Point point;
	bool alive;
	bool killed;
	float x;
	float y;
	
public:

	// Display
	void draw();

	// Constructor
	Killer();

	// Getters
	Point getPoint() const { return point; }
	float getX() const { return point.getX(); }
	float getY() const { return point.getY(); }

	
	
	// setters

	void setPoint(Point pt) { point = pt; }
	void setAlive(bool alive);
	
	// Stub functions
	
	void advance(float x, float y);

	
	
};

#endif



