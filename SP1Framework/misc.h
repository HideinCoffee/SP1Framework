#pragma once
#include "position.h"
#include "map.h"
#include "Bullet.h"

enum class MISCTYPE {
	COIN,
	TRAP,
	CHANGEPAD,
	AMMO,
	HEALTH,
	DOOR,
	LAVA,
	GOAL
};
class misc
{
private:

	bool destroyed;
	bool moveable;
	MISCTYPE objectype;
	Position position;
	BULLETYPE bulletype;

public:
	misc(MISCTYPE objectypetoset,int x,int y);
	~misc();
	virtual void shoot(Map &map) = 0;
	//setters
	void setx(int x);
	void sety(int y);
	void setPos(COORD position);
	void setdestroy(bool destruct);
	//getters
	bool getdestroystatus();
	COORD returnPos();
	void setobjectype(MISCTYPE objectypetoset);
	void collide(Map &map);
	

};

