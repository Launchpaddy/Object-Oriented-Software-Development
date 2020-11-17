#ifndef ship_h
#define ship_h
#define SHIP_SIZE 10
#define START_TIME 60
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define REVERSE_THRUST_AMOUNT 0.1
#include "flyingObject.h"

class Ship : public FlyingObject
{
public:
	Ship();
	void draw();
	void rotateRight();
	void rotateLeft();
	void thrust();
	void reverseThrust();
	float getAngle()          { return angle; }
	void setThrusting(bool t) { thrusting = t; }
	int  getStartTime()        { return startTime;  }
	void resetStartTime()     { startTime = START_TIME; }
	void displayGameOver();
	void displayNextLevel();
private:
	float angle;
	bool thrusting;
	int startTime; // how much time the ship will have a shield up
};

#endif /* ship_h */
