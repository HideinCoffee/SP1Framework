#include "Rendercharacter.h"

void rendercharacter(Console &g_Console,SGameChar &g_sChar,Entity* entityarray[]) {
	WORD charcolor = 0x23;

	g_Console.writeToBuffer((entityarray[0]->getX() - g_sChar.offset.X) * 2, entityarray[0]->getY() - g_sChar.offset.Y, "  ", 0x0f);
}