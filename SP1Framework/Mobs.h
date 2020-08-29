#pragma once
#include "Entity.h"
#include "Map.h"
#include "global.h"
#include <ctime>

class Mobs :public Entity
{
private:
	MOVEMENTDIRECTION mobdirection;
	int movecount;
	int movenum;
	bool trackplayermode;
	bool canshoot;

public:
	Mobs(int xpos, int ypos, int movenum , int health,char symbol, bool canshoot, bool trackplayermode, MOVEMENTDIRECTION &mobdirection);
	~Mobs();
	bool checkmove(COORD playerrpos);
	void move(MOVEMENTDIRECTION &movementdir,COORD mobpos, Map &map); ///more parameters, but suff here must be added to the entity class
	void shoot(BULLETDIRECTION bulletdir,int index);
	void trackplayer(COORD playerpos,Map &map);
	void controlledmovement(Map& map);
	bool movementcollide(Map& map, int x, int y);
	void AOEdamage(COORD playerpos);
};