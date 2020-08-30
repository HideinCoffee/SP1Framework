#include "Entity.h"
Entity::~Entity(){
	//deconstructor
}
Entity::Entity(int health,bool alive,int x, int y) {
	COORD entitypos;
	entitypos.X = x;
	entitypos.Y = y;
	this->health = health;
	this->alive = alive;
	setpos(entitypos);
}
void Entity::setpos(COORD position) {
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

void Entity::takedamage(int x) {
	if (health <= 0)
		setalive(false);
	else
		sethealth((health - x));
}

bool Entity::getalive() {
	return alive;
}