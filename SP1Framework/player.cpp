#include "player.h"

Player::Player(Map& map, BULLETYPE bulletype, int x, int y) :Entity(30, true, 'P',0,0) {
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

void Player::move(MOVEMENTDIRECTION &movementdir,COORD pos,Map &map) {
	COORD tempcord = pos;
	bool moved = false;

	switch (movementdir.UP) {
	case true:
		
		if (movementcollide(map, tempcord.X, tempcord.Y-1) == false) {
			tempcord.Y -= 1;
			movementdir.UP = false;
			moved = true;
		}
		break;
	case false:
		movementdir.UP = false;
		break;
	}

	switch (movementdir.DOWN) {
	case true:
		
		if (movementcollide(map, tempcord.X, tempcord.Y+1) == false) {
			tempcord.Y += 1;
			movementdir.DOWN = false;
			moved = true;
		}
		
		break;
	case false:
		movementdir.DOWN = false;
		break;
	}

	switch (movementdir.LEFT) {
	case true:
		if (movementcollide(map, tempcord.X-1, tempcord.Y) == false) {
			tempcord.X -= 1;
			movementdir.LEFT = false;
				moved = true;
		}
		break;
	case false:
		movementdir.LEFT = false;
		break;
	}

	switch (movementdir.RIGHT) {
	case true:
		if (movementcollide(map, tempcord.X+1, tempcord.Y) == false) {
			tempcord.X += 1;
			movementdir.RIGHT = false;
			moved = true;
		}
		break;

	case false:
		movementdir.RIGHT = false;
		break;
	}

	if (moved == true)
		setpos(tempcord);
}

void Player::shoot(BULLETDIRECTION bulletdir) {
	for (int i = 0; i < 100; i++) {
		if (bulletarray[i] == nullptr) {
			bulletarray[i] = new Bullet(getX(), getY(), bulletdir, BULLETYPE::B_P);
			break;
		}
	}
}

bool Player::movementcollide(Map &map,int x, int y){
	bool returnvalue = true;
	switch (map.getchar(x,y)) {
	case '#':
		returnvalue = true;
		break;
	case '!':
		setrescued(getrescued() + 1);// npc rescue count +=1;
		returnvalue = true;
		break;
	case '$':
		setmoney(getmoney() + 1);// money +=1;
		map.editmap(x,y, ' ');
		returnvalue = false;
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
		returnvalue = true;
		break;	
	case 'm':
		damage(1);
		// take DOT
		// check hp level if it is below zero 
		returnvalue = true;
		break;
	case 'x': // traps 
		damage(1);
		returnvalue = true;
		break;
		// samething check player hp.
	case ' ':
		returnvalue = false;
	}
	return returnvalue;
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
