#include "Renderyoudied.h"
#include "Rectangle.h"
#include "Rendermainmenu.h"
void renderdeathscreen(Console& g_Console, SMouseEvent& g_mouseEvent, EGAMESTATES& g_eGameState) {
	rectangle(g_Console, 0, 0, 160, 40, ' ', 0x99, 0x99); //background 
	rectangle(g_Console, 70, 25, 20, 5, ' ', 0x66, 0x77); // retry button
	rendertext(g_Console, 77, 27, "RETRY", 0x80);
	switch (g_mouseEvent.eventFlags) {
	case 0:
		// retry button
		if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && buttonpress(g_mouseEvent, 70, 25, 20, 5))
			g_eGameState = EGAMESTATES::S_GAME;
	}
}
