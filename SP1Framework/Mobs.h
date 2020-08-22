#pragma once
#include "Entity.h"
#include <ctime>

class Mobs :public Entity
{
public:
	bool needtomove;
	Mobs(int x, int y);
	~Mobs();
	void checkmove(COORD pos);
	void move(MOVEMENTDIRECTION movementdir,COORD pos); ///more parameters, but suff here must be added to the entity class
};