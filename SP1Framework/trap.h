#pragma once//??
#include "Entity.h"
#include "Map.h"
#include "global.h"
#include "misc.h"

class Traps :public misc
{
public:
	Traps(BULLETYPE bulletype,int x, int y);
	~Traps();
	void shoot(BULLETDIRECTION bulletdirect);
	void collide(Map& map);
	void damage(int x);

};