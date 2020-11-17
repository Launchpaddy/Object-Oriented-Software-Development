###############################################################
# Program:
#     Project 09, Skeet
#     Brother Comeau, CS165
# Author:
#     Trevik Peterson
# Summary:
#     A bird wil be randomly generated on the left side of the screen and 
#     move across alowing for the user to shoot at it. If it is hit 
#     then the bird and the bullet dies and a new bird is generated.
#     If bird leaves the screen it dies and an new bird is generted.
#     points are added each time a bird is shot.
# Above and Beyond
#     There is not a Limit to how many bullets the user has
#     They start with 20 and get 5 more for killing a bird
#     if the miss enough and run out of bullets the game stops 
#     making new birds and bullets.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bird.o toughBird.o sacredBird.o regularBird.o velocity.o bullet.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bird.o toughBird.o sacredBird.o regularBird.o velocity.o bullet.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h toughBird.h velocity.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
flyingObject.o: flyingObject.cpp flyingObject.h
	g++ -c flyingObject.cpp

bird.o: bird.cpp bird.h
	g++ -c bird.cpp

toughBird.o: toughBird.cpp toughBird.h
	g++ -c toughBird.cpp

sacredBird.o: sacredBird.cpp sacredBird.h
	g++ -c sacredBird.cpp

regularBird.o: regularBird.cpp regularBird.h 
	g++ -c  regularBird.cpp

bullet.o: bullet.cpp bullet.h
	g++ -c bullet.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
