#ifndef BIRD_H
#define BIRD_H 
#include "flyingObject.h"

class Bird : public FlyingObject
{

protected:
	int hitCount;
	float yC;
	float xC;
	float rand;
	float hSpeed;
	float vSpeed;
public:
	Bird();
	
   void advance();
   virtual float getHspeed() { return hSpeed; }
   virtual void setHspeed(float hs) { hSpeed = hs; }
   virtual float getVspeed() { return vSpeed; }
   virtual void setVspeed(float vs) { vSpeed = vs; }
	
	virtual void draw();
	void kill();
   virtual int hit();   // when the bird is shot
	
};



#endif