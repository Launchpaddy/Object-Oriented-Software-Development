#include "ship.h"
#include "velocity.h"
#include "uiDraw.h"


/**********************************************
* SHIP  CONSTRUCTOR
***********************************************/
Ship::Ship()
{
	thrusting = false;
	angle = 0;
	startTime = START_TIME; // 3 seconds? ish
}

/**********************************************
* SHIP DRAW
***********************************************/
void Ship::draw()
{
	drawShip(getPoint(), angle, thrusting);
	if (startTime > 0)
	{
		drawCircle(getPoint(), 10);
		startTime--;
	}
	
}

/**********************************************
* SHIP THRUST
***********************************************/
void Ship::thrust()
{
	
	vel.setDy(-(THRUST_AMOUNT * (-cos(PI / 180.0 * angle))));
	vel.setDx(-(THRUST_AMOUNT * (sin(PI / 180.0 * angle))));
	
}

/**********************************************
* SHIP THRUST REVERSE
***********************************************/
void Ship::reverseThrust()
{
	vel.setDy((REVERSE_THRUST_AMOUNT * (-cos(PI / 180.0 * angle))));
	vel.setDx((REVERSE_THRUST_AMOUNT * (sin(PI / 180.0 * angle))));
}

/**********************************************
* DISPLAY GAME OVER 
***********************************************/
void Ship::displayGameOver()
{
	Point middle;
	middle.setX(-40);
	Point nextLine;
	nextLine.setY(-20);
	nextLine.setX(-138);
	drawText(middle, "GAME OVER");
	drawText(nextLine, "PRESS R TO RESTART, C TO CONTINUE LEVEL");

}

/**********************************************
* DISPLAY NEXT LEVEL
***********************************************/
void Ship::displayNextLevel()
{
	Point middle;
	middle.setX(-80);
	middle.setY(20);
	drawText(middle, "INCOMING ASTROID FIELD!!");

}

/**********************************************
* SHIP ROTATE RIGHT
***********************************************/
void Ship::rotateRight()
{
	angle -= ROTATE_AMOUNT;

}

/**********************************************
* SHIP ROTATE LEFT
***********************************************/
void Ship::rotateLeft()
{
	angle += ROTATE_AMOUNT;
}
