#pragma once
#include "Position.h"
#include <string>

class Entity
{
protected:

	Position position;


public:

	Entity();
	~Entity();
	virtual void move(std::string direction) = 0; //Function prototype
	int getX();
	int getY(); //Getters, to pove things from private to public
	Position returnPos();

};