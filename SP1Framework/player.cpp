#include "player.h"
Player::Player(){
	//pos.X = 80;
//	pos.Y = 20;
	//default constructor
}
Player::Player(int x, int y) {
	COORD P;
	P.X = x;
	P.Y = y;
	setpos(P);
}
void Player::move(MOVEMENTDIRECTION movementdir,COORD pos,Map &map) {
	
}

void Player::shoot(BULLETDIRECTION bulletdir) {
	for (int i = 0; i < 20; i++) {
		if (bulletarray[i] == nullptr) {
			bulletarray[i] = new Bullet(getX(), getY(), bulletdir, BULLETYPE::B_P);
			break;
		}
	}
}
//void setpos(COORD pos) {
//	position.setpos(pos);
//}