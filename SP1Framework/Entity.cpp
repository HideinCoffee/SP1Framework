#include "Entity.h"

Entity::Entity() //this is a base class
{
	//Stuff that's needed for this is already done in other files. So this remains empty


}

Entity::~Entity()
{
	//deconstructor
}

int Entity::getX()
{
	return position.getX(); //Gets your X position from Position Header file
}

int Entity::getY()
{
	return position.getY(); //Gets your Y position from Position Header file
}

Position Entity::returnPos()
{
	return Position();
}

