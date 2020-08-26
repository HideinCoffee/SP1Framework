#include "trap.h"

//Traps::Traps(BULLETYPE bulletype, int x, int y)
//{
//	COORD trap;
//	trap.X = x;
//	trap.Y = y;
//	setpos(trap);
//	Constructor for traps
//}

Traps::~Traps() {
	//destructor for traps
}


void Traps::shoot(BULLETDIRECTION bulletdir) {
	//for (int i = 0; i < 20; i++) {
	//	if (bulletarray[i] == nullptr) {
	//		bulletarray[i] = new Bullet(getX(), getY(), bulletdir, BULLETYPE::B_P);
	//		break;
	//	}
	//}
}

void Traps::collide(Map& map) {

}

void Traps::damage(int x) {

}