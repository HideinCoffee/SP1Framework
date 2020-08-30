#pragma once
#include "Framework/console.h"
#include <string>
#include "Map.h"
#include "position.h"

struct MOVEMENTDIRECTION {
	bool UP;
	bool DOWN;
	bool LEFT;
	bool RIGHT;
};


enum class BULLETDIRECTION {
		B_UP,
		B_DOWN,
		B_LEFT,
		B_RIGHT,
	};

enum class BULLETYPE {
	B_P, // player
	B_E,		//  normal enemy
	B_B, // boss 
	B_T // trapbullet
};

class Entity
{

private:
	int health;
	bool alive;
	Position position;
public:
	~Entity();
	Entity(int health,bool alive,int x, int y);

	// move function
	virtual void move(MOVEMENTDIRECTION &movementdir,COORD pos,Map &map) = 0; //Function prototype
	
	//Getters, to get private datamembers
	COORD returnPos();
	//int gethealth();
	bool getalive();
	//setters to set private datamembers
	void setpos(COORD pos);
	void sethealth(int health);
	void setalive(bool alive);
	virtual void shoot(BULLETDIRECTION bulletdir,int index) = 0;
	virtual bool movementcollide(Map &map,int x, int y) = 0;
	virtual int getdamage() = 0;
	void takedamage(int x);
	int gethealth();
};