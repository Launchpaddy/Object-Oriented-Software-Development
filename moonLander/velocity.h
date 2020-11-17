#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity 
{
private:
	float dx;
	float dy;
	// don't think I will need these but.. why not.
	float x;
	float y;


public:
	// constructors
	Velocity();
	Velocity(float dx, float dy); 
	// getters
	float getDx() const { return dx; };  
	float getDy() const { return dy; }; 
	// setters
	void setDx(float dx);
	void setDy(float dy);
	// De-constructor
	~Velocity();

	
};

#endif
