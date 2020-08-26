#include "Entity.h"

Entity::~Entity(){
	//deconstructor
}
Entity::Entity(int health,bool alive, char symbol)
{
	this->health = health;
	this->alive = alive;
	this->symbol = symbol;
}


int Entity::getX(){
	return position.getX(); //Gets your X position from Position Header file
}

int Entity::getY(){
	return position.getY(); //Gets your Y position from Position Header file
}
void Entity::setpos(COORD pos) {
	position.setPos(pos);
}
COORD Entity::returnPos(){
	COORD entitypos = position.returnPos();
	return entitypos;
}

int Entity::gethealth() {
	return health;
}

void Entity::sethealth(int health) {
	this->health = health;
}

void Entity::setalive(bool alive) {
	this->alive = alive;
}

char Entity::getsymbol() {
	return symbol;
}

void Entity::setsymbol(char symbol) {
	this->symbol = symbol;
}
