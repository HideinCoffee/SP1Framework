#pragma once
#include "Position.h"
#include "Framework/console.h"
#include <string>
#include "Map.h"

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
	B_C, // corona
	B_B // player 
};

class Entity
{
private:
	Position position;
	int health;
	char prevchar;
	bool alive;
public:
	Entity();
	~Entity();
	virtual void move(MOVEMENTDIRECTION movementdir,COORD pos,Map &map) = 0; //Function prototype
	void setpos(COORD pos);
	int getX();
	int getY(); //Getters, to pove things from private to public
	COORD returnPos();
	int gethealth();
	void sethealth(int x);
	void setalive(bool live);
	virtual void shoot(BULLETDIRECTION bulletdir) =0;
	virtual void collide(Map &map) = 0;
	virtual void damage(int x)=0;
};