###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Comeau, CS165
# Author:
#     Trevik Peterson
# Summary:
#     The Program allows for the user to fly the ship arround and shoot bullets
#     at large astroids flying around. when a large astroid is hit it breaks up into
#     smaller astroids.
# Above and Beyond
#     LEVELS   - Each time you kill all of the astroids the next level starts with 1 more astroid then before.
#
#     BULLETS  - Each level your gun increses the number of bullets it shoots by 2.
#
#	   SHEILD   - When a new level begins you will have a sheild that makes it so you do dont die but you cant 
#                shoot ether until the sheild is down which is about 2 seconds.
#              - You can move out of the astroids way when you have your sheild up.
#
#     DELAY    - Before each level begins there is about a 3 second delay which allows left over bullets
#                to die and give the user some time to get ready for the next level and to read message.
#
#	   RESTART  - You can restart the game at any time and it will reset you to the first level.
#
#     CONTINUE - You can continue(restart) the level you are curently on. 
#
#     DISPLAYS * Top left always tells you which level you are on.
#			      * After each level when you are wating for the next level is says "INCOMING ASTROID FIELD!!"
#              * When you die it says "GAME OVER", "PRESS R TO RESTART, C TO CONTINUE LEVEL"
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
