#include "lander.h"
#include "uiDraw.h"
#include "velocity.h"
#include "point.h"


/*****************************************
 * Default constructor for lander
 *****************************************/
Lander::Lander()
{

	point = Point(0,0);
	vel = Velocity();
	landed = false;
	alive = true;
	fuel = 0;
	killed = false;
}

/*****************************************
 * Draw calls drawLander in uiDraw
 *****************************************/
void Lander :: draw()
{
	//drawLargeAsteroid(point, 1);
	drawLander(point);
	
}

// setters

/*****************************************
 * Sets if landed
 *****************************************/
void Lander :: setLanded(bool l)
{
	landed = l;
}

/*****************************************
 * Sets if alive
 *****************************************/
void Lander::setAlive(bool alive) 
{
	this->alive = alive;
}

/*****************************************
 * Sets the amount of fuel
 *****************************************/
void Lander::setFuel(int f) 
{
	fuel += f;
}

// apply

/*****************************************
 * Applys gravity to lander
 *****************************************/
void Lander::applyGravity(float g) 
{

	vel.setDy(-0.1);
}

/*****************************************
 *  Applys thrust to the lander when the LEFT arrow is used
 *****************************************/
void Lander::applyThrustLeft() 
{
	vel.setDx(0.1);
	setFuel(-1);
	
}

/*****************************************
 *  Applys thrust to the lander when the RIGHT arrow is used
 *****************************************/
void Lander::applyThrustRight()
{
	vel.setDx(-0.1);
	setFuel(-1);
}

/*****************************************
 *  Applys thrust to the lander when the DOWN arrow is used
 *****************************************/
void Lander::applyThrustBottom()
{
	vel.setDy(0.3);
	setFuel(-3);
}

/*****************************************
 *  Moves the lander to what ever the values of dx and dy are
 *****************************************/
void Lander :: advance()
{
	point.addX(vel.getDx());
	point.addY(vel.getDy());
	
}



