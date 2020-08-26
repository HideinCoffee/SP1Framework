#pragma once
#include "Entity.h"
#include "framework/console.h"
#include "global.h"

class Player : public Entity
{
private:
	int remainingammo;
	int rescued;
	BULLETYPE bulletype;
	int money;
public:
	// player constructor
	Player(Map &map,BULLETYPE bulletype,int x, int y);
	//void setpos(COORD pos);
	void move(MOVEMENTDIRECTION &movementdir,COORD pos,Map &map);
	void shoot(BULLETDIRECTION bulletdirection);
	bool movementcollide(Map &map,int x, int y);
	void damage(int x);
	// setters
	void setbulletype(BULLETYPE bulletype);
	void setammo(int ammo);
	void setrescued(int rescued);
	void setmoney(int money);
	//getters
	BULLETYPE getbulletype();
	int getrescued();
	int getammo();
	int getmoney();
};


