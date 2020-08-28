#include "trap.h"


Trap::Trap(Map& map, BULLETYPE bulletype, int x, int y) : misc(MISCTYPE::TRAP, map, x, y, 'x') {
	setbulletype(bulletype);
	//map.editmap(x, y, 'x');
}

void Trap::shoot(BULLETDIRECTION bulletdir) {
	for (int i = 0; i < 20; i++) {
		if (bulletarray1[i] == nullptr) {
			bulletarray1[i] = new Bullet(returnPos().X, returnPos().Y, bulletdir, BULLETYPE::B_C);
			break;
		}
	}
}

void Trap::setbulletype(BULLETYPE bulletype) {
	this->bulletype = bulletype;
}

BULLETYPE Trap::getbulletype() {
	return bulletype;
}

void Trap::setpos(COORD position) {
	setx(position.X);
	sety(position.Y);
}