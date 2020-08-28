#include "Entity.h"

Entity::~Entity(){
	//deconstructor
}
Entity::Entity(int health,bool alive, char symbol,int x, int y) {
	COORD entitypos;
	entitypos.X = x;
	entitypos.Y = y;
	this->health = health;
	this->alive = alive;
	this->symbol = symbol;
	setpos(entitypos);
	
}

void Entity::setpos(COORD position) {
	//this->position = position;
	this->position.setPos(position);
}

COORD Entity::returnPos(){
	return position.returnPos();
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
