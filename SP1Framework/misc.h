#pragma once
#include "position.h"
#include "map.h"
#include "Bullet.h"

enum class MISCTYPE {
	COIN,
	TRAP,
	CHANGEPAD,
	AMMO,
	HEALTH
};
class misc
{
private:

	bool destroyed;
	bool moveable;
	MISCTYPE objectype;
	Position position;
	BULLETYPE bulletype;
	char symbol;

public:
	misc(MISCTYPE objectypetoset,Map &map,int x,int y, char miscsymbol);
	~misc();
	virtual void shoot(Map &map) = 0;
	//setters
	void setx(int x);
	void sety(int y);
	void setPos(COORD position);
	void setdestroy(bool destruct);
	void setsymbol(char symbol);
	//getters
	bool getdestroystatus();
	COORD returnPos();
	void setobjectype(MISCTYPE objectypetoset);
	void collide(Map &map);
	char getsymbol();

};

