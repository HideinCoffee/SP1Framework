#include "misc.h"

misc::misc(MISCTYPE objectypetoset,int x, int y) {
	switch (objectypetoset) {
	case MISCTYPE::COIN:
		setobjectype(objectypetoset);
		moveable = false;
	case MISCTYPE::CHANGEPAD:
		setobjectype(objectypetoset);
		moveable = false;
		break;
	case MISCTYPE::TRAP:
		setobjectype(objectypetoset);
		moveable = false;
		break;
	case MISCTYPE::DOOR:
		setobjectype(objectypetoset);
		moveable = false;
		break;
	case MISCTYPE::LAVA:
		setobjectype(objectypetoset);
		moveable = false;
		break;
	case MISCTYPE::GOAL:
		setobjectype(objectypetoset);
		moveable = false;
		break;
	}
	setx(x);
	sety(y);
}

misc::~misc() {
	//deconstructor 
}

void misc::setobjectype(MISCTYPE objectypetoset) {
	objectype = objectypetoset;
}


void misc::setx(int x) {
	position.setX(x);
}

void misc::sety(int y) {
	position.setY(y);
}

void misc::collide(Map &map) { // player collide with misc
	
}

bool misc::getdestroystatus() {
	return destroyed;
}

void misc::setdestroy(bool destruct) {
	destroyed = destruct;
}


COORD misc::returnPos() {
	return position.returnPos();
}

void misc::setPos(COORD position) {
	this->position.setPos(position);
}