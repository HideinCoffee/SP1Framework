#include "Rendermainmenu.h"

void rendermainmenu(Console& g_Console,SMouseEvent &g_mouseEvent,EGAMESTATES &g_eGameState) {
	rectangle(g_Console, 0, 0, 160, 40,' ', 0xdd, 0xdd);
	
	rectangle(g_Console, 70, 25, 20, 5,' ', 0x00, 0x88);
	rendertext(g_Console, 77, 27, "START", 0x80);
	
	switch (g_mouseEvent.eventFlags) {
	case 0:
		if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (buttonpress(g_mouseEvent,70,25,20,5) == true)) {
			g_eGameState = EGAMESTATES::S_GAME;
		}
	}
}

bool buttonpress(SMouseEvent &g_mouseEvent,int posx, int posy, int width, int height){
	COORD mouseposition = { 0,0 };
	bool returnvalue = false;
	int startx = posx;
	int starty = posy;
	int endx = startx + width;
	int endy = starty + height;
	mouseposition.X = g_mouseEvent.mousePosition.X;
	mouseposition.Y = g_mouseEvent.mousePosition.Y;
	for (int row = startx; row < endx; row++) {
		for (int col = starty; col < endy; col++) {
			if ((row == mouseposition.X) && (col == mouseposition.Y)) {
				returnvalue = true;
				break;
			}
		}
		if (returnvalue == true)
			break;
	}
	return returnvalue;
}
