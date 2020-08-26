#pragma once
#include "Entity.h"
#include "Map.h"
#include "global.h"
#include <ctime>

class Mobs :public Entity
{
public:
	bool needtomove;
	Mobs(int x, int y,char symbol);
	~Mobs();
	void checkmove(COORD pos);
	void move(MOVEMENTDIRECTION &movementdir,COORD pos, Map &map); ///more parameters, but suff here must be added to the entity class
	void shoot(BULLETDIRECTION bulletdir);
	bool movementcollide(Map &map,int x, int y);
	void damage(int x);
	void trackplayer(COORD pos,Map &map);

};