#pragma once
#include "Framework/console.h"
class Position
{
public:
	COORD pos;
	Position();
	~Position();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setPos(COORD position);
	COORD returnPos();
};