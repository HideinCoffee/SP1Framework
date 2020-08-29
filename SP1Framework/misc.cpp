#include "misc.h"

misc::misc(MISCTYPE objectypetoset,Map &map,int x, int y,char miscsymbol) {
	switch (objectypetoset) {
	case MISCTYPE::COIN:
		setobjectype(objectypetoset);
		moveable = false;
		map.editmap(x, y, '$');
		break;
	case MISCTYPE::CHANGEPAD:
		setobjectype(objectypetoset);
		moveable = false;
		map.editmap(x, y, 'T');
		break;
	case MISCTYPE::TRAP:
		setobjectype(objectypetoset);
		moveable = true;
		map.editmap(x, y,'x');
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

char misc::getsymbol() {
	return symbol;
}
COORD misc::returnPos() {
	return position.returnPos();
}


void misc::setsymbol(char symbol) {
	this->symbol = symbol;
}

void misc::setPos(COORD position) {
	this->position.setPos(position);
}