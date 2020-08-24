#pragma once
#include "Entity.h"
#include "framework/console.h"
#include "global.h"

class Player : public Entity
{
public:
	// player constructor
	Player();
	Player(int x, int y);
	//void setpos(COORD pos);
	void move(MOVEMENTDIRECTION,COORD pos,Map &map);
	void shoot(BULLETDIRECTION bulletdirection);
};


