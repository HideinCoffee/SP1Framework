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
	B_P,
	B_C,
	B_B
};
class Entity
{
private:
	Position position;
	int health;
	char prevchar;
public:
	Entity();
	~Entity();
	virtual void move(MOVEMENTDIRECTION movementdir,COORD pos,Map &map) = 0; //Function prototype
	void setpos(COORD pos);
	int getX();
	int getY(); //Getters, to pove things from private to public
	COORD returnPos();
	virtual void shoot(BULLETDIRECTION bulletdir);
	
};