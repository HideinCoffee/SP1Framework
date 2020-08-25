#include "player.h"
Player::Player(){
	//pos.X = 80;
//	pos.Y = 20;
	//default constructor
}
Player::Player(Map& map,BULLETYPE bulletype,int x, int y) {
	COORD P;
	P.X = x;
	P.Y = y;
	setpos(P);
	setbulletype(bulletype);
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
		setrescued(getrescued() + 1);// npc rescue count +=1;
		break;
	case '$':
		setmoney(getmoney() + 1);// money +=1;
		break;
	case 'B':
		switch (getbulletype()) { // check whos bullet if its enemy take damage
		case BULLETYPE::B_P:
			break;
		case BULLETYPE::B_B:
			break;
		case BULLETYPE::B_C:
			break;
		}
		break;
	case 'm':
		damage(1);
		// take DOT
		break;
	case 'X': // traps 
		damage(1);
		break;
	}
}
void Player::damage(int x) {
	if (gethealth() - x > 0)
		sethealth(gethealth() - x);
	else
		setalive(false);
}

void Player::setbulletype(BULLETYPE bulletype) {
	currentbulletype = bulletype;
}

void Player::setammo(int ammo) {
	remainingammo = ammo;
}

void Player::setrescued(int rescued) {
	npcrescued = rescued;
}

void Player::setmoney(int money) {
	totalmoney = money;
}

BULLETYPE Player::getbulletype() {
	return currentbulletype;
}

int Player::getrescued() {
	return npcrescued;
}

int Player::getammo() {
	return remainingammo;
}
int Player::getmoney() {
	return totalmoney;
}
