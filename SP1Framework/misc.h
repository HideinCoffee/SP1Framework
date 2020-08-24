#pragma once
#include "position.h"
#include "map.h"
enum class MISCTYPE {
	COIN,
	TRAP,
	CHANGEPAD,

};
class misc
{
private:
	bool moveable;
	MISCTYPE objectype;
	Position position;


public:
	misc(MISCTYPE objectypetoset,Map &map,int x,int y);
	~misc();
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
	void setobjectype(MISCTYPE objectypetoset);
	void collide(Map &map);
};

