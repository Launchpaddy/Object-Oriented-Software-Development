/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include "bullet.h"
#include "bird.h"
#include "toughBird.h"
#include "sacredBird.h"
#include "regularBird.h"

#include <vector>
#include <iostream> // added for error checking
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   // Set up the initial conditions of the game
   score = 0;
	count = 20;
	lost = false;
   // Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;
   //cerr << "bird had been set to null\n";
   if (bird == NULL)
   {
     // cerr << "bird is null at beginning\n";
   }
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a bird allocated
   //       and if so, delete it.
   if (bird != NULL)
   {
     
       delete bird; 
   }
   

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceBird();

   handleCollisions();
   cleanUpZombies();
}

/******************************************
* BULLET COUNTER! 
* Added by yours truly
* When a bullet leaves the screen lose a bullet
******************************************/
void Game::bulletCounter(int b)
{
	
	count += b;

}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
	
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {

		if (count <= 0)
		{
			lost = true;
		}
	

      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
				bulletCounter(-1);
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
  // cerr << "advanceBird\n";
   if (bird == NULL)
   {
      // there is no bird right now, possibly create one
    
      // "resurrect" it will some random chance
      if (random(0, 30) == 0)
      {
         // create a new bird
        // cerr << "a bird should be made!!!\n";
         bird = createBird();
      }
   }
   else
   {
      //cerr << "bird is not null\n";
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         //cerr << "bird is alive?\n";
         // move it forward
         bird->advance();
         
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
   }
   
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{ 
	if (count > 0)
	{
		Bird* newBird = NULL;



		//cerr << " new bird is about to be  made\n";

		// rand will be a random number between 1 and 9 
		// this way there can be more regualr birds then tough birds
		int rand = random(1, 10);

		if (rand <= 5)
		{
			//cerr << "Regualar bird was made" << endl;
			newBird = new RegularBird();
		}
		else if (rand <= 7)
		{
			//cerr << "Tough bird was made" << endl;
			newBird = new ToughBird();
		}
		else
		{
			//cerr << "Sacred bird was made" << endl;
			newBird = new SacredBird();
		}


		return newBird;

	}
	else
		return NULL;
} 

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
					count += 5;
               
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet
      
      // TODO: Clean up the memory used by the bird
      delete bird;
      bird = NULL;
		if (bird == NULL)
		{
			 //cerr << "bird succesfuly deleted\n\n";
		}
   
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace() && !isLost()) // if you run out of bullets
   {
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      
      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the bird

   // TODO: Check if you have a valid bird and if it's alive
   // then call it's draw method
   if (bird != NULL )//&& bird->isAlive())
   {
      //cerr << "bird is being drawn\n";
       bird->draw();
   }
 
  

   // draw the rifle
   rifle.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
	Point countLocation;
   
	countLocation.setX((topLeft.getX() * -1) - 20);
	countLocation.setY((topLeft.getY()) - 10);
	
	drawNumber(countLocation, count);

   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   
   drawNumber(scoreLocation, score);

}

