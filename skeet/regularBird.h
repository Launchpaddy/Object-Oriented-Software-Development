#ifndef REGULAR_BIRD_H
#define REGULAR_BIRD_H 

#include "bird.h"

class RegularBird : public Bird
{
public:
	RegularBird()
	{
			// Every thing we need is in Bird
	}
	void draw(); // exept for draw
};

#endif