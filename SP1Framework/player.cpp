#include "player.h"

Player::Player(Map& map, BULLETYPE bulletype, int x, int y):Entity (0,true, 'P') {
	COORD P;
	P.X = x;
	P.Y = y;
	setpos(P);
	setbulletype(bulletype);
	map.editmap(x, y, 'P');
	rescued = 0;
	money = 0;
	remainingammo = 20;
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

void Player::movementcollide(Map &map,int x, int y){

	switch (map.getchar(getX(),getY())) {
	case '!':
		setrescued(getrescued() + 1);// npc rescue count +=1;
		break;
	case '$':
		setmoney(getmoney() + 1);// money +=1;
		map.editmap(getX(), getY(), '@');

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
	case 'x': // traps 
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
	this->bulletype = bulletype;
}

void Player::setammo(int ammo) {
	remainingammo = ammo;
}

void Player::setrescued(int npcrescued) {
	this->rescued = rescued;
}

void Player::setmoney(int money) {
	this->money = money;
}

BULLETYPE Player::getbulletype() {
	return bulletype;
}

int Player::getrescued() {
	return rescued;
}

int Player::getammo() {
	return remainingammo;
}
int Player::getmoney() {
	return money;
}
