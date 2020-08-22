#include "Position.h"

Position::Position()
{
	//blank for now
}
//To randomise movement of ghost, both X and Y coordinates
//this file is Only for randomising


Position::~Position()
{
	//deconstructor
}

int Position::getX()
{
	return pos.X; //getter
}

int Position::getY()
{
	return pos.Y; //getter
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

