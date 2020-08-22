#pragma once
#include "Position.h"
#include "Framework/console.h"
#include <string>
struct MOVEMENTDIRECTION {
	bool UP;
	bool DOWN;
	bool LEFT;
	bool RIGHT;
};
class Entity
{
public:
	Position position;
	Entity();
	~Entity();
	virtual void move(MOVEMENTDIRECTION movementdir,COORD pos) = 0; //Function prototype
	void setpos(COORD pos);
	int getX();
	int getY(); //Getters, to pove things from private to public
	COORD returnPos();

};