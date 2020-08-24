#include "player.h"
Player::Player(){
	//pos.X = 80;
//	pos.Y = 20;
	//default constructor
}
Player::Player(Map& map,int x, int y) {
	COORD P;
	P.X = x;
	P.Y = y;
	setpos(P);
	//map.editmap(x, y, 'P');
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

void Player::collide(Map &map) {

	switch (map.getchar(getX(),getY())) {
	case '!':
		break;
	case '$':
		break;
	case 'B':
		break;
	case 'm':
		break;
	case 'T':
		break;
	case 'X':
		break;
	}


}
void Player::damage(int x) {
	if (gethealth() - x > 0)
		sethealth(gethealth() - x);
	else
		setalive(false);
}
//void setpos(COORD pos) {
//	position.setpos(pos);
//}