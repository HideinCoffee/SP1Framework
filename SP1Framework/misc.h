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
	bool destroyed;
	bool moveable;
	MISCTYPE objectype;
	Position position;


public:
	misc(MISCTYPE objectypetoset,Map &map,int x,int y);
	~misc();
	//setters
	void setx(int x);
	void sety(int y);
	void setdestroy(bool destruct);
	//getters
	bool getdestroystatus();
	COORD returnPos();
	void setobjectype(MISCTYPE objectypetoset);
	void collide(Map &map);
	

};

