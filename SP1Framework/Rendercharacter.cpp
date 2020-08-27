#include "Rendercharacter.h"

void rendercharacter(Console &g_Console,SGameChar &g_sChar,Entity* playerarray[]) {
	WORD charcolor = 0x23;
	if (g_sChar.m_bActive == true)
		charcolor = 0x0A;
	g_Console.writeToBuffer((playerarray[0]->getX() - g_sChar.offset.X) * 2, playerarray[0]->getY() - g_sChar.offset.Y, "  ", 0xff);
}