###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Comeau, CS165
# Author:
#     Trevik Peterson
# Summary:
#     This program will allow a user to play the game moonLander. 
#     
# Above and Beyond
#     I made it so that the Moon Lander comes out of the sky with thrust allready
#     as if it was coming out of orbit.
#     I also made a death star that will chase you around and if it hits you 
#     you wont be able to fly anymore.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o killer.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o killer.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.cpp lander.h velocity.cpp velocity.h point.h point.cpp
	g++ -c lander.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

killer.o: killer.cpp killer.h velocity.cpp velocity.h point.h point.cpp
	g++ -c killer.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
