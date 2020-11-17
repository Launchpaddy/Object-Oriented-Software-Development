#ifndef TOUGH_BIRD_H
#define TOUGH_BIRD_H 
#include "bird.h"
#include "uiDraw.h"

class ToughBird : public Bird
{

private:
	int lives;

public:
	// Costom speed Tough Bird
	ToughBird()
	{
		lives = 3;
		setHspeed(random(2,5));
		setVspeed(random(1,4));
	}
	
	virtual void draw();

	virtual int hit() // when the bird is shot
	{ 
		lives--;
		if ( lives == 0 ) 
		{
			kill(); 
			hitCount += 2; // extra point for it being killed
		}
		return hitCount;
   }
	
};

#endif