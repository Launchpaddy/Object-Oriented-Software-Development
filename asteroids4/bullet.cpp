#include "bullet.h"

#include "uiDraw.h"
#include "flyingObject.h"
#include "velocity.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "game.h"
#include "ship.h"
#include <math.h>

#define BULLET_SPEED 10.0


/*******************************************
* Constructor for bullets
*********************************************/
Bullet::Bullet()
{
	setPoint(0, 0); 
	angle = 0;
	killed = false;
	timer = 0;
}

/*******************************************
* Fires a bullet where the gun is pointing
*********************************************/
void Bullet::fire(Point p, float angle, Velocity velocity) 
{
	point = p;
	angle += 90;
	float x = (cos((PI / 180.0) * angle) * BULLET_SPEED);
	float y = (sin((PI / 180.0) * angle) * BULLET_SPEED);
	x += velocity.getDx();
	y += velocity.getDy();
	vel.setDx(x);
	vel.setDy(y);
}

/*******************************************
* Draws the dot on screen
*********************************************/
void Bullet::draw()
{
	
	drawDot(getPoint());
	timer++;
	if (timer == BULLET_LIFE) { kill();  }

}