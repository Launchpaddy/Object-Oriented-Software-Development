#include "velocity.h"

/*****************************************
* Default constructor for Velocity
*****************************************/
Velocity::Velocity()
{
	dx = 0;
	dy = 0;
}

/*****************************************
* Default constructor for Velocity with parameters
*****************************************/
Velocity::Velocity(float dx, float dy)
{
	setDx(dx);
	setDx(dy);
}

/*****************************************
* Sets DX
*****************************************/
void Velocity::setDx(float dx)
{
	this->dx += dx;
}

/*****************************************
* Sets DY
*****************************************/
void Velocity::setDy(float dy)
{
	this->dy += dy;
}

/*****************************************
* De-constructor
*****************************************/
Velocity::~Velocity()
{

}
