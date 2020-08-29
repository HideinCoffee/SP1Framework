#include "Rendercharacter.h"

void rendercharacter(Console &g_Console,Map &map,SGameChar &g_sChar,Entity* playerarray[]) {
	WORD charcolor = 0x23;
	if (g_sChar.m_bActive == true)
		charcolor = 0x0A;
	if (playerarray[0]->getalive() == true) {
		g_Console.writeToBuffer((playerarray[0]->returnPos().X - g_sChar.offset.X) * 2, playerarray[0]->returnPos().Y - g_sChar.offset.Y, "  ", 0xff);
	}
	
}