#include "RenderUI.h"

void renderinterface(Console& g_Console) {
	COORD maxint = g_Console.getMaxConsoleSize();
	COORD minint;
	minint.X =  maxint.X -= 30;
	minint.Y =  maxint.Y -= 20;
	g_Console.writeToBuffer(133,7,32, 0xff);
}




