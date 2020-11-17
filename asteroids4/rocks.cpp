#include "rocks.h"
#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

/***********************************************
* Default Constructor for ROCK
*************************************************/
Rock::Rock()
{
	lives = 3;
	rotate = random(0,361);
	setPoint(0, 0);
	upOrDown = random(1, 3);
}


/***********************************************
* Default Constructor for BIG ROCK
*************************************************/
BigRock::BigRock()
{
	vel.setDx(random(-1, 2));
	vel.setDy(random(-1, 2));
}

/***********************************************
* DRAW 
* calls uIdraw with a point and a rotation
*************************************************/
void BigRock :: draw()
{
	rotate += BIG_ROCK_SPIN;
	drawLargeAsteroid(getPoint(), rotate);

	
}

/***********************************************
* Default Constructor for MEDIUM ROCK
*************************************************/
MediumRock::MediumRock()
{

	lives = 2;

}

/***********************************************
* DRAW
* calls uIdraw with a point and a rotation
*************************************************/
void MediumRock::draw()
{
	rotate += MEDIUM_ROCK_SPIN;
	drawMediumAsteroid(getPoint(), rotate);
}


/***********************************************
* Default Constructor for SMALL ROCK
*************************************************/
SmallRock::SmallRock()
{
	lives = 1; // redundant but we dont want to have some random number for a small rock
}

/***********************************************
* DRAW
* calls uIdraw with a point and a rotation
*************************************************/
void SmallRock::draw()
{
	rotate += SMALL_ROCK_SPIN;
	drawSmallAsteroid(getPoint(), rotate);
}




