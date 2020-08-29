#pragma once
#include "Framework/console.h"
#include "Global.h"
#include "Rectangle.h"

enum class USERINTERFACE {
	HEALTH,
	AMMO,
	NPCRESCUED,
	LEGEND,

};
void renderinterface(Console &g_Console);
void renderinfobar(Console &g_Console);
void renderplayerposition(Console& g_Console);
void renderlegend(Console &g_Console);
void rendertext(Console &g_Console, int startx, int start, std::string txttorender,WORD txtcolor);


