#pragma once
#include "Framework/console.h"
#include "RenderUI.h"
#include "game.h"
void rendermainmenu(Console& g_Console,SMouseEvent &g_mouseEvent,EGAMESTATES &g_eGameState);

bool buttonpress(SMouseEvent& g_mouseEvent,int posx, int posy, int width, int height);
