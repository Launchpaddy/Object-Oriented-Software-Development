#ifndef SACRED_BIRD_H
#define SACRED_BIRD_H 
#include "bird.h"

class SacredBird : public Bird
{

private:
	int penalty;

public:
	SacredBird()
	{
		penalty = -10;
	}
	
	virtual void draw();

	virtual int hit() // when the bid is shot
	{ 
	
		kill();
		
		return penalty;
   }
	
};



#endif