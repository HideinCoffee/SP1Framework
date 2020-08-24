#include "misc.h"

misc::misc(MISCTYPE objectypetoset,Map &map,int x, int y) {
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
		map.editmap(x, y,'X');
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

int misc::getx() {
	return position.getX();
}

int misc::gety() {
	return position.getY();
}

void misc::setx(int x) {
	position.setX(x);
}

void misc::sety(int y) {
	position.setY(y);
}

void misc::collide(Map &map) { // player collide with misc
	
}






