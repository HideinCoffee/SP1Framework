#pragma once
#include "Framework/console.h"
#include "Global.h"
enum class USERINTERFACE {
	HEALTH,
	AMMO,
	NPCRESCUED,
	LEGEND,
	
};
void renderinterface(Console & g_Console);

void renderhealth(Console &g_Console,COORD maxint);

void rendertext(Console& g_Console, int startx, int start, std::string txttorender,WORD txtcolor);