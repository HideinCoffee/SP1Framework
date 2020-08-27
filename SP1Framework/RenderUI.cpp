#include "RenderUI.h"

void renderinterface(Console& g_Console) {
	rectangle(g_Console, 130, 0, 29, 40, ' ', 0x99, 0x77);
	renderinfobar(g_Console); 
	renderlegend(g_Console);
}

void renderinfobar(Console& g_Console) {
	
	COORD healthpos;
	healthpos = g_Console.getConsoleSize();
	healthpos.X -= 150;
	healthpos.Y -= 3;

	rendertext(g_Console, healthpos.X, healthpos.Y, "Health:", 0x0f);
	//int playerhealth = playerarray[0]->gethealth();
	for (int i = 0; i < 30; i++) {
		g_Console.writeToBuffer(healthpos.X+10+i, healthpos.Y,' ',0xAA);
	}
	healthpos.X + 50;
	renderplayerposition(g_Console);
}
void renderplayerposition(Console& g_Console) {
	COORD c = g_Console.getConsoleSize();
	c.X -= 150;
	c.Y -= 1;
	std::ostringstream ss;
	ss.str("");
	ss << "Player position:" << " X:" << playerarray[0]->getX() << " " << "Y:" << playerarray[0]->getY();
	g_Console.writeToBuffer(c.X,c.Y,ss.str(), 0x0f);
}

void rendertext(Console& g_Console, int startx, int starty,std::string txttorender,WORD txtcolor) { // figure out how to scale it 
	COORD txtpos;
	txtpos.X = startx;
	txtpos.Y = starty;
	int txtlength =txttorender.length();
	
	for (int i = 0; i < txtlength; i++) {
		char txtrender = txttorender[i];
		g_Console.writeToBuffer(txtpos.X + i, txtpos.Y,txtrender,txtcolor);
	}
}
//IMPT REMEMBER TO CHANGE THE CONSOLE AT THE BOTTOM WILL CONTAIN THE PLAYER HEALTH ETC
// SIZE WILL BE X 160 Y 5;

void renderlegend(Console& g_Console){
	COORD pos;
	pos = g_Console.getConsoleSize();
	pos.X -= 20;
	pos.Y -= 38;
	rendertext(g_Console, pos.X, pos.Y, "Legend:", 0x70); // LEGEND:
	pos.X -= 13;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "#", 0x00); // wall 

}
