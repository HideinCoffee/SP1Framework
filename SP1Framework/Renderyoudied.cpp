#include "Renderyoudied.h"
#include "Rectangle.h"
#include "Rendermainmenu.h"
#include "delete.h"


void renderdeathscreen(Console& g_Console, SMouseEvent& g_mouseEvent, EGAMESTATES& g_eGameState,Map& map) {
	rectangle(g_Console, 0, 0, 160, 40, ' ', 0x99, 0x99); //background 
	rectangle(g_Console, 70, 25, 20, 5, ' ', 0x66, 0x77); // retry button
	rendertext(g_Console, 77, 27, "RETRY", 0x80);
	switch (g_mouseEvent.eventFlags) {
	case 0:
		// retry button
		if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && buttonpress(g_mouseEvent, 70, 25, 20, 5)) {
			g_eGameState = EGAMESTATES::S_GAME;
			reload();
			playerarray[0] = new Player(map, BULLETYPE::B_P, 0, 5, 5, 30, 5);
			//memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
			map.slotmap("Tutorial.csv", g_Console);
		}
	}
}
