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
	return x; //getter
}

int Position::getY()
{
	return y; //getter
}

void Position::setX(int x)
{
	this->x = x; //setter
}

void Position::setY(int y)
{
	this->y = y; //setter
}
void Position::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

Position Position::returnPos()
{
	return Position();
}

