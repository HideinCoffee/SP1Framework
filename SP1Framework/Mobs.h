#pragma once
#include "Entity.h"
#include "Map.h"
#include "global.h"
#include <ctime>

class Mobs :public Entity
{
	

private:
	bool needtomove;
	MOVEMENTDIRECTION mobdirection;
	int movecount;
	int movenum;
	bool reverse;
	bool trackplayermode;

public:
	Mobs(int xpos, int ypos, int movenum , char symbol, bool trackplayermode, MOVEMENTDIRECTION &mobdirection);
	~Mobs();
	void checkmove(COORD pos);
	void move(MOVEMENTDIRECTION &movementdir,COORD mobpos, Map &map); ///more parameters, but suff here must be added to the entity class
	void shoot(BULLETDIRECTION bulletdir);
	bool movementcollide(Map &map,int x, int y);
	void damage(int x);
	void trackplayer(COORD mobpos,Map &map);
	void controlledmovement(COORD mobpos, Map& map);
};