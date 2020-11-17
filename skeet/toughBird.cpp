#include "toughBird.h"
#include "uiDraw.h"

/*******************************************
* Draws a bird.. which is a circle + how man lives are left
*********************************************/
void ToughBird :: draw()
{
	drawToughBird(getPoint(), 15, lives);
}
