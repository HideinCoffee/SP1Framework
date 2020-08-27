#include "RenderUI.h"


void renderinterface(Console& g_Console) {
	COORD maxint = g_Console.getConsoleSize();
	maxint.X -= 30;
	maxint.Y -= 20;
	rendertext(g_Console, 130, 20, "Health",0x0f);
}

void renderhealth(Console& g_Console,COORD maxint) {
	playerarray[0]->gethealth();
}

//void rendermoney(Console& g_Console, COORD maxint)
//{
//
//}

void rendertext(Console& g_Console, int startx, int starty,std::string txttorender,WORD txtcolor) { // figure out how to scale it 
	COORD txtpos;
	txtpos.X = startx;
	txtpos.Y = starty;
	int txtlength =txttorender.length();
	
	for (int i = 0; i < txtlength; i++) {
		char txtrender = txttorender[i];
		g_Console.writeToBuffer(txtpos.X + 1, txtpos.Y,txtrender,txtcolor);
		txtpos.X++;
	}
}
//IMPT REMEMBER TO CHANGE THE CONSOLE AT THE BOTTOM WILL CONTAIN THE PLAYER HEALTH ETC
// SIZE WILL BE X 160 Y 5;
