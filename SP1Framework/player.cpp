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
void Player::move(MOVEMENTDIRECTION movementdir,COORD pos) {
	
}

//void setpos(COORD pos) {
//	position.setpos(pos);
//}