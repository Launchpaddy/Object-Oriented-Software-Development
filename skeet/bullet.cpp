#include "bullet.h"
#include "uiDraw.h"
#include "flyingObject.h"
#include "velocity.h"
#include "uiInteract.h"
#include "game.h"
#include <math.h>
#define PI 3.14159

/*******************************************
* Constructor for bullets 
*********************************************/
Bullet :: Bullet()
{
	setPoint(100,-100); // usualy where the gun is 
	angle = 0;
	killed = false;
}


/*******************************************
* Fires a bullet where the gun is pointing
*********************************************/
void Bullet::fire(Point p, float angle) // angle should be from 0 to 90
{
	// starts the bullet at p, which is the bottom right corner, where the gun is
	point = p;
   vel.setDx(-cos(angle * PI/180) * 10); // ten is the bullet speed
   vel.setDy(sin(angle * PI/180) * 10);
	
}

/*******************************************
* Draws the dot on screen
*********************************************/
void Bullet :: draw()
{
	//std::cout << "Amount of Bullets: " << bAmount << std::endl;
	drawDot(getPoint());

}

