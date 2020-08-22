#pragma once
#include "Entity.h"
#include "framework/console.h"

class Player : public Entity
{
	
public:
	// player constructor
	Player();
	Player(int x, int y);
	//void setpos(COORD pos);
	void move(MOVEMENTDIRECTION movementdir,COORD pos);
};


