#pragma once
#include "Entity.h"
#include "Map.h"
#include "global.h"
#include <ctime>

class Mobs :public Entity
{
public:
	bool needtomove;
	Mobs(int x, int y);
	~Mobs();
	void checkmove(COORD pos);
	void move(MOVEMENTDIRECTION movementdir,COORD pos, Map &map); ///more parameters, but suff here must be added to the entity class
	void shoot(BULLETDIRECTION bulletdir);
	void collide(Map &map);
	void damage(int x);

};