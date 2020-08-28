#include "RenderUI.h"
#include "player.h"

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
	int healthcolor = 0xAA;
	int playerhealth = playerarray[0]->gethealth();
	rendertext(g_Console, healthpos.X, healthpos.Y, "Health:", 0x0f);
	if ((playerhealth <= 30) && (playerhealth > 20))
		healthcolor = 0xAA;
	else if ((playerhealth <= 20) && (playerhealth > 10))
		healthcolor = 0x66;
	else if ((playerhealth <= 10))
		healthcolor = 0x44;
	for (int i = 0; i < playerhealth; i++) {
		g_Console.writeToBuffer(healthpos.X+10+i, healthpos.Y,"  ",healthcolor);
	}
	
	healthpos.X + 50;
	renderplayerposition(g_Console);

	COORD moneypos;
	moneypos = g_Console.getConsoleSize();
	moneypos.X -= 120;
	moneypos.Y -= 3;
	int moneycolour = 0x66;
	std::string renderplayermoney = std::to_string(((Player*)(playerarray[0]))->getmoney());
	rendertext(g_Console, moneypos.X, moneypos.Y, "Coins:", 0x0f);
	rendertext(g_Console, moneypos.X + 7, moneypos.Y, renderplayermoney, 0x0f);
}
void renderplayerposition(Console& g_Console) {
	COORD c = g_Console.getConsoleSize();
	c.X -= 150;
	c.Y -= 1;
	std::ostringstream ss;
	ss.str("");
	ss << "Player position:" << " X:" << playerarray[0]->returnPos().X << " " << "Y:" << playerarray[0]->returnPos().Y;
	g_Console.writeToBuffer(c.X,c.Y,ss.str(), 0x0f);
}

void rendertext(Console& g_Console, int startx, int starty,std::string txttorender,WORD txtcolor) { 
	COORD txtpos;
	txtpos.X = startx;
	txtpos.Y = starty;
	int txtlength =txttorender.length();
	
	for (int i = 0; i < txtlength; i++) {
		char txtrender = txttorender[i];
		g_Console.writeToBuffer(txtpos.X + i, txtpos.Y,txtrender,txtcolor);
	}
}


void renderlegend(Console& g_Console){ // convert to csv !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	COORD pos;
	pos = g_Console.getConsoleSize();
	pos.X -= 20;
	pos.Y -= 38;
	rendertext(g_Console, pos.X, pos.Y, "Legend:", 0x70); // LEGEND:
	pos.X -= 6;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "Wall:", 0x70);
	pos.X += 7;
	rendertext(g_Console, pos.X, pos.Y, "  ", 0x00); // wall
	pos.X -= 7;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "Path:", 0x70);
	pos.X += 7;
	rendertext(g_Console, pos.X, pos.Y, "  ", 0x88);
	pos.X -= 7;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "Coins", 0x70);
	pos.X += 7;
	rendertext(g_Console, pos.X, pos.Y, "  ", 0x66);
	pos.X -= 7;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "Traps", 0x70);
	pos.X += 7;
	rendertext(g_Console, pos.X, pos.Y, "  ", 0x55);
	pos.X -= 7;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "Mobs", 0x70);
	pos.X += 7;
	rendertext(g_Console, pos.X, pos.Y, "  ", 0xCC);
	pos.X -= 7;
	pos.Y += 3;
	rendertext(g_Console, pos.X, pos.Y, "Npc", 0x70);
	pos.X += 7;
	rendertext(g_Console, pos.X, pos.Y, "  ", 0x22);
	//pos.X ;
	//pos.Y += 3;
	//rendertext(g_Console, pos.X, pos.Y, "#", 0x00); // wall 

}
