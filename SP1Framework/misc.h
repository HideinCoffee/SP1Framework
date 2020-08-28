#pragma once
#include "position.h"
#include "map.h"
#include "Bullet.h"

enum class MISCTYPE {
	COIN,
	TRAP,
	CHANGEPAD,
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
	virtual void shoot(BULLETDIRECTION bulletdirection) = 0;
	//setters
	void setx(int x);
	void sety(int y);
	void setdestroy(bool destruct);
	void setsymbol(char symbol);
	//getters
	bool getdestroystatus();
	int getx();
	int gety();
	void setobjectype(MISCTYPE objectypetoset);
	void collide(Map &map);
	char getsymbol();

};

