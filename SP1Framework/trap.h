#pragma once
#include "misc.h"
#include "Global.h"

class Trap : public misc {
private :
	BULLETOWNER bulletowner;
	int index;
	int damage;
	BULLETYPE bulletype;
	BULLETDIRECTION bulletdirection;
	Bullet* trapbulletarray[100];
	bool canshoot;
	bool activated;
	int speed; 
	double g_dElapsedtime;
public :
	Trap(Map& map, int posx, int posy,int index, int damage,BULLETDIRECTION bulletdirection,BULLETYPE bulletype,bool shoot,bool activated,int speed);
	~Trap();
	void shoot(Map &map);
	void renderbullet(Map& map);
	Bullet* returntrpbullarray();
};





