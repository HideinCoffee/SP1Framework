#pragma once
#include "Framework/console.h"
class Position
{
private:
	COORD pos;
public:
	Position();
	~Position();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setPos(COORD position);
	COORD returnPos();
};