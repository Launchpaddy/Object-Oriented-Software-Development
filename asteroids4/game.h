/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/


#ifndef GAME_H
#define GAME_H

#include <list>
#include <limits>
#include <algorithm>
#include <vector>
#include "rocks.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "ship.h"


#define CLOSE_ENOUGH 15
#define OFF_SCREEN_BORDER_AMOUNT 5
#define NUM_ROCK_START 5
#define DELAY_TIME 60
#define START_LEVEL 0
#define WRAP_DISTANCE (END_POSITION_MAX - 1)
#define START_POSITIONS_MAX - 200
#define END_POSITION_MAX  200

 /*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
	/*********************************************
	* Constructor
	* Initializes the game
	*********************************************/
	Game(Point tl, Point br);
	~Game();

	/*********************************************
	* Function: handleInput
	* Description: Takes actions according to whatever
	*  keys the user has pressed.
	*********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	* Function: advance
	* Description: Move everything forward one
	*  step in time.
	*********************************************/
	void advance();

	/*********************************************
	* Function: draw
	* Description: draws everything for the game.
	*********************************************/
	void draw(const Interface & ui);

	

	/*********************************************
	* Closest Distance
	**********************************************/
	float getClosestDistance(const FlyingObject & obj1, const FlyingObject & obj2) const;

private:
	/*************************************************
	* Private methods to help with the game logic.
	*************************************************/
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;
	int level;
	bool continueGame;
	int nextLevelDelay;

	bool isOnScreen(const Point & point);
	
	void nextLevel();
	void advanceBullets();
	void advanceRock();
	void advanceShip();

	std::list<Rock*> rocks;
	std::list<Bullet*> bullets;
	Ship  ship;

	void handleCollisions();
	void cleanUpZombies();
};

#endif /* GAME_H */
