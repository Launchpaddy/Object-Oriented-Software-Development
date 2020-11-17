#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


class Lander 
{

private:
	Velocity vel;
	Point point;
	bool landed;
	bool alive;
	bool killed;
	int fuel;
	

	
public:

	// Display
	void draw();

	// Constructor
	Lander();

	// Getters
	// added for killer
	float getX() const { return point.getX(); }
	float getY() const { return point.getY(); }

	//
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return vel; } 
	int getFuel() const { return fuel; }
	bool isAlive() const { return alive; }
	bool isLanded() const { return landed; }
	bool gotKilled() const { return killed; }
	bool canThrust() const 
	{ 
		if (fuel > 0 && !isLanded() && !gotKilled())
			return true; 
		else 
			return false;
	}

	// setters
	void setVelocity(Velocity vl) { vel = vl; }
	void setPoint(Point pt) { point = pt; }
	void setLanded(bool landed);
	void setAlive(bool alive);
	void setFuel(int fuel);
	void setKilled(bool killed) { this->killed = killed; }
	
	// Mover functions
	void applyGravity(float g);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();

	
	
};

#endif



