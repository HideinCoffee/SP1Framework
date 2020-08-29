#pragma once
#include "Entity.h"
#include "framework/console.h"
#include "global.h"

class Player : public Entity
{
private:
	int rescued;
	BULLETYPE bulletype;
	int money;
	int damage;
	Bullet* plrbullarray[100];
public:
	// player constructor
	Player(Map &map,BULLETYPE bulletype,int x, int y,int health,int damage);
	//void setpos(COORD pos);
	void move(MOVEMENTDIRECTION &movementdir,COORD pos,Map &map);
	void shoot(BULLETDIRECTION bulletdir,int index);
	bool movementcollide(Map &map,int x, int y);
	//void takedamage(int x);
	// setters
	void setbulletype(BULLETYPE bulletype);
	void setrescued(int rescued);
	void setmoney(int money);
	//getters
	BULLETYPE getbulletype();
	int getrescued();
	int getmoney();
	void renderplayerbullet(Map &map);
};


