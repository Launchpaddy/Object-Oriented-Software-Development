#include "killer.h"
#include "lander.h"
#include "uiDraw.h"
#include "velocity.h"
#include "point.h"
#include <iostream>
#include <cmath>
using namespace std;

/*****************************************
 * Default constructor for Killer
 *****************************************/
Killer::Killer()
{
	point = Point(0,0);
	alive = true;
	
}

/*****************************************
 * Draw calls drawLander in uiDraw
 *****************************************/
void Killer :: draw()
{

	if(alive)
	{
		drawSacredBird(point, 10);
	}
	
}

// setters


/*****************************************
 * Sets if alive
 *****************************************/
void Killer::setAlive(bool alive) 
{
	this->alive = alive;
}

/*****************************************
 *  Moves the killer closer to the Lander
 *  It takes in the lander x and y.
 *****************************************/
void Killer :: advance(float lx, float ly)
{
	x = getX();
	y = getY();

	if ( x < lx)
	{
		point.addX(1.75);
	}
	else 
		point.addX(-1.75);

	if ( y < ly)
	{
		point.addY(1.75);
	}
	else 
		point.addY(-1.75);


}



