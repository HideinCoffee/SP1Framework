#include "Position.h"

Position::Position()
{
	pos.X = 0;
	pos.Y = 0;
}

Position::~Position()
{
	//deconstructor
}

void Position::setX(int x)
{
	pos.X = x; //setter
}

void Position::setY(int y)
{
	pos.Y = y; //setter
}
void Position::setPos(COORD position)
{
	pos.X = position.X;
	pos.Y = position.Y;
}

COORD Position::returnPos()
{
	return pos;
}

