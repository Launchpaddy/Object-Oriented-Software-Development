#ifndef rocks_h
#define rocks_h
#include "flyingObject.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4
#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

/*********************************************
*	ROCK BASE CLASS
*********************************************/
class Rock : public FlyingObject
{

protected:
	int upOrDown;
	int rotate;
	int lives;
public:
	Rock();
	void setLives(int lives) { this->lives = lives; }
	int getLives() { return lives; }
	virtual void draw() = 0;

};


/*********************************************
*	BIG ROCK
*********************************************/
class BigRock : public Rock
{
public:
	BigRock();
	void draw();

private:

};


/*********************************************
*	MEDIUM ROCK
*********************************************/
class MediumRock : public Rock
{
public:
	MediumRock();
	void draw();
private:

};

/*********************************************
*	SMALL ROCK
*********************************************/
class SmallRock : public Rock
{
public:
	SmallRock();
	void draw();

private:

};

#endif /* rocks_h */
