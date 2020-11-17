/*************************************************************
* File: game.cpp
* Author: Br. Burton / Trevik Peterson
* Description: Contains the implementaiton of the game class
*  methods.
*************************************************************/


// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"
#include <vector>
#include <iostream> // added for error checking
using namespace std;

/***************************************
* GAME CONSTRUCTOR
***************************************/
Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
	// Set up the initial conditions of the game
	for (int i = 0; i < NUM_ROCK_START; ++i) // will make as many large rocks as we want
	{
		Rock * r = new BigRock();
		r->setPoint(random(START_POSITIONS_MAX, END_POSITION_MAX), random(START_POSITIONS_MAX, END_POSITION_MAX));
		rocks.push_back(r);
		
	}


	level = START_LEVEL;  // what level are we on
	continueGame = false; // we aren't restarting yet
	nextLevelDelay = DELAY_TIME; // delay between levels #setUpTime.. and yes that is just a hashtag

}

/****************************************
* GAME DESTRUCTOR
****************************************/
Game :: ~Game()
{
	// Check to see if there is currently a rock allocated
	// and if so, delete it.
	for (list<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
	{
		it = rocks.erase(it);
	}
	
}

/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
***************************************/
void Game::advance()
{
	advanceBullets();
	advanceRock();
	advanceShip();
	handleCollisions();
	cleanUpZombies();
}

/***************************************
* GAME :: ADVANCE BULLETS
* Go through each bullet and advance it.
***************************************/
void Game::advanceBullets()
{


	for (list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it)
	{
		if ((*it)->isAlive())
		{
			(*it)->advance();
		}
		
	}
	
}

/**************************************************************************
* GAME :: ADVANCE ship
**************************************************************************/
void Game::advanceShip()
{
	ship.advance();
}

/**************************************************************************
* GAME :: ADVANCE rock
**************************************************************************/
void Game::advanceRock()
{

	for (list<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
	{
		if ((*it)->isAlive())
		{
			(*it)->advance();
		}
		
	}
	
}


/**************************************************************************
* GAME :: IS ON SCREEN
* Determines if a given point is on the screen.
**************************************************************************/
bool Game::isOnScreen(const Point & point)
{
	return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
		&& point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}



/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between a rock and a bullet.
**************************************************************************/
void Game::handleCollisions()
{
	
	// now check for a hit (if it is close enough to any live bullets)

	for (list<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
	{
		Rock* pRocks = *it;
		if (ship.isAlive() && !ship.getStartTime())
		{

			if ((getClosestDistance(ship, *pRocks) < CLOSE_ENOUGH)
				&& (getClosestDistance(ship, *pRocks)) < CLOSE_ENOUGH)
			{
				//we have a hit!

				// hit the rock
				pRocks->setAlive(false);
				// the bullet is dead as well
				ship.setAlive(false); //$###################################

			}
		}
		for (list<Bullet*>::iterator bIt = bullets.begin(); bIt != bullets.end(); ++bIt)
		{
			Bullet* pBullets = *bIt;
			if ((*bIt)->isAlive()) 
			{
				
				if (pRocks->isAlive()) // kills the rock with bullets
				{


					if ((getClosestDistance(*pBullets, *pRocks) < CLOSE_ENOUGH)
						&& (getClosestDistance(*pBullets, *pRocks)) < CLOSE_ENOUGH)
					{
						//we have a hit!
						pRocks->setAlive(false);
						// the bullet is dead as well
						(*bIt)->kill();
						//bullets[i].kill();
					}


				}

	
			}

		}
		

	} 
}


/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects (take bullets out of the list, deallocate rock)
**************************************************************************/
void Game::cleanUpZombies()
{
	
	list<Rock*>::iterator rocksIt = rocks.begin();
	int i = 0;
	while (i != rocks.size())
	{
	   Rock* pRocks = *rocksIt;
		
		if (!pRocks->isAlive())
		{
			// Rocks have different lives depending on what size they are
			// large rocks have 3 lives, medium 2, small 1
			// If a large rock dies make two medium and one small
			if (pRocks->getLives() == 3)
			{
				Rock * r = new SmallRock();
				r->setPoint(pRocks->getPoint());
				r->setVelocity(pRocks->getVelocity());
				r->setDx(pRocks->getDx() + 2);
				rocks.push_back(r);

				Rock * r2 = new MediumRock();
				r2->setPoint(pRocks->getPoint());
				r2->setVelocity(pRocks->getVelocity());
				r2->setDy(pRocks->getDy() + 1);
				rocks.push_back(r2);

				Rock * r3 = new MediumRock();
				r3->setPoint(pRocks->getPoint());
				r3->setVelocity(pRocks->getVelocity());
				r3->setDy(pRocks->getDy() - 1);
				rocks.push_back(r3);

			}
		   if (pRocks->getLives() == 2) // if a medium dies make two small
			{
				Rock * r = new SmallRock();
				r->setPoint(pRocks->getPoint());
				r->setVelocity(pRocks->getVelocity());
				r->setDx(pRocks->getDx() + 3);
				rocks.push_back(r);

				Rock * r2 = new SmallRock();
				r2->setPoint(pRocks->getPoint());
				r2->setVelocity(pRocks->getVelocity());
				r2->setDx(pRocks->getDx() - 3);
				rocks.push_back(r2);
				
			}
				
			rocksIt = rocks.erase(rocksIt);	// if a small dies we dont care and we delete it
			
		}
		else
		{
			i++; //only want to run for how many rocks we have 
			rocksIt++; // advance itorator
		}
		
		
	}
	
	// NEXT LEVEL OR RESTART GAME
	if (rocks.size() <= 0)
	{
		
		ship.displayNextLevel(); // a waring for the user to get ready for fun
		if (nextLevelDelay == 0) // wating for the right time
		{
			level++;
			for (list<Bullet*>::iterator bIt = bullets.begin(); bIt != bullets.end(); ++bIt)
			{
				bIt = bullets.erase(bIt);
			}
	
			for (int i = 0; i < (NUM_ROCK_START + level); ++i) // will make as many large rocks as we want
			{
				Rock * r2 = new BigRock();
				r2->setPoint(random(START_POSITIONS_MAX, END_POSITION_MAX), random(START_POSITIONS_MAX, END_POSITION_MAX));
				rocks.push_back(r2);
			}
			ship.resetStartTime();
			continueGame = false;
			nextLevelDelay = DELAY_TIME;
		}
		else
			nextLevelDelay--; // we want to count down for the delay time until we are ready to play
	}
	
	
	// Look for dead bullets
	list<Bullet*>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet* pBullet = *bulletIt;
	
		if (!(*pBullet).isAlive())
		{
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}

	
}

/*******************************************
* NEXT LEVEL 
* gets called when there are no more rocks on the screen
* which happens if you beat the level or restart the game
***********************************************/
void Game::nextLevel()
{
	ship.resetStartTime();
	ship.setPoint(Point());
	ship.setAlive(true);
	ship.setVelocity(Velocity());
	do
	{
		for (list<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
		{
			it = rocks.erase(it);
		}
	} while (rocks.size() != 0);

	for (list<Bullet*>::iterator bIt = bullets.begin(); bIt != bullets.end(); ++bIt)
	{
		bIt = bullets.erase(bIt);
	}
}

/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface & ui)
{
	if (ship.isAlive()) // only want input from user if ship is alive
	{

		// Change the direction 
		if (ui.isLeft())
		{
			ship.rotateLeft();
		}
		if (ui.isUp())
		{
			ship.setThrusting(true); // shows flame at the back of the ship
			ship.thrust();
		}
		else
			ship.setThrusting(false); // added just for fun
		
		if (ui.isDown()) // added just for fun
		{
			ship.reverseThrust();
		}

		if (ui.isRight())
		{
			ship.rotateRight();
		}

		// Check for "Spacebar
		if (ui.isSpace() && !ship.getStartTime()) 
		{
			
			for (int i = -level; i <= level; i++)
			{
				Bullet* newBullet = new Bullet();
				(*newBullet).fire(ship.getPoint(), (ship.getAngle() + i ), ship.getVelocity());
				bullets.push_back(newBullet);
			}
		
		}
		
	}
	if (ui.isRestart())
	{	
		level = (START_LEVEL - 1);
		nextLevel();		
	}
	if (ui.isContinue() && level >= 0 && !ship.isAlive())
	{
		level--;
		nextLevel();
	}
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface & ui)
{
	// draw the rocks
	for (list<Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
	{
		(*it)->draw();

	}
	// draw the ship
	if (ship.isAlive())
	{
		ship.draw();
	}
	// draw the bullets
	for (list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it)
	{
		if ((*it)->isAlive())
		{
			(*it)->draw();
		}

	}
	// find where we want to put "LEVEL"
	Point levelLocation;
	levelLocation.setX(topLeft.getX() + 5);
	levelLocation.setY(topLeft.getY() - 11);
	drawText(levelLocation, "LEVEL#");
	// find where we want to put which level we are on
	Point scoreLocation;
	scoreLocation.setX(topLeft.getX() + 55);
	scoreLocation.setY(topLeft.getY() - 2);
	drawNumber(scoreLocation, level + 1);

	// if the ship  is dead put up the game over screen
	if (!ship.isAlive())
	{
		ship.displayGameOver();	
	}
	
}


/**********************************************************
* Function: getClosestDistance
* Description: Determine how close these two objects will
*   get in between the frames.
**********************************************************/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
// find the maximum distance traveled
float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
dMax = max(dMax, abs(obj2.getVelocity().getDx()));
dMax = max(dMax, abs(obj2.getVelocity().getDy()));
dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

float distMin = std::numeric_limits<float>::max();
for (float i = 0.0; i <= dMax; i++)
{
Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

float xDiff = point1.getX() - point2.getX();
float yDiff = point1.getY() - point2.getY();

float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

distMin = min(distMin, distSquared);
}

return sqrt(distMin);
}

