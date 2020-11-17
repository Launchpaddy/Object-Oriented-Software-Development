#include "bird.h"
#include "uiDraw.h"
#include "game.h"

/*******************************************
* Constructor for bird
*********************************************/
Bird :: Bird ()
{
	rand = random(-200,200);
	hSpeed = random(3,7);
	vSpeed = random(1, 4);
	xC = -200;
	yC = rand;
	hitCount = 1;     // hate to get zero for first kill
	setPoint(xC, yC); // starts bird at left of screen at a random y 

}

/*******************************************
* Draws a bird.. which is a circle 
*********************************************/
void Bird :: draw()
{
	//drawCircle(getPoint(), 15);
}

/*******************************************
* Addvance just moves the bird across the screen for now.
*********************************************/
void Bird :: advance()
{
	if (rand > 100)
	{
		point.addY(-getVspeed());
	}
	if (rand < -100)
	{
		point.addY(getVspeed());
	}
	else
	{
		point.addY(0);
	}
	//float speed = random(2,5);
	point.addX(getHspeed()); 
   
	
	
}

/*******************************************
* Kills the bird if it leaves the screen
*********************************************/
void Bird :: kill()
{
	setAlive(false);
}

/*******************************************
* Kills the bird and returns 1 point for hit count
*********************************************/
int Bird :: hit()
{
	//kill();
	alive = false;
	return hitCount; // = 1
}