#include "Renderoptions.h"
#include "Rectangle.h"
#include "Rendermainmenu.h"
void renderoptions(Console& g_Console, SMouseEvent& g_mouseEvent, EGAMESTATES &g_eGameState) {
	// movement instructions
	rectangle(g_Console, 0, 0, 160, 40, ' ', 0x00, 0x00);
	rendertext(g_Console, 80, 5, "INSTRUCTIONS:", 0x0f);
	rendertext(g_Console, 30, 7, "MOVEMENT", 0x0f);
	rendertext(g_Console, 30, 9, "W To MOVE UP", 0x0f);
	rendertext(g_Console, 30, 11, "S TO MOVE DOWN", 0x0f);
	rendertext(g_Console, 30, 13, "A TO MOVE LEFT", 0x0f);
	rendertext(g_Console, 30, 15, "D TO MOVE LEFT", 0x0f);

	///shooting instructions
	rendertext(g_Console, 50, 7, "SHOOT", 0x0f);
	rendertext(g_Console, 50, 9, "ARROW UP TO SHOOT UP", 0x0f);
	rendertext(g_Console, 50, 11, "ARROW DOWN TO SHOOT DOWN", 0x0f);
	rendertext(g_Console, 50, 13, "ARROW LEFT TO SHOOT LEFT", 0x0f);
	rendertext(g_Console, 50, 15, "ARROW RIGTH TO SHOOT RIGHT", 0x0f);


	rectangle(g_Console, 70, 25, 20, 5, ' ', 0x00, 0x00);
	rendertext(g_Console, 77, 27, "RESUME", 0x0f);

	rectangle(g_Console, 70, 35, 20, 5, ' ', 0x00, 0x0);
	rendertext(g_Console, 78, 37, "QUIT", 0x0f);
	switch (g_mouseEvent.eventFlags) {
	case 0:
		if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (buttonpress(g_mouseEvent, 70, 25, 20, 5) == true)) { // quit game
			g_eGameState = EGAMESTATES::S_SPLASHSCREEN;
		}
		if ((g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) && (buttonpress(g_mouseEvent, 70, 35, 20, 5) == true)) { // resume game
			g_eGameState = EGAMESTATES::S_QUIT;
		}
		break;
	}
}