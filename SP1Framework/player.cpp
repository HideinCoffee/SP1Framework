#include "player.h"
#include "map.h"
Player::Player(Map& map, BULLETYPE bulletype, int x, int y,int health,int damage) :Entity(0, true, 'P',0,0) {
	COORD P;
	P.X = x;
	P.Y = y;
	setpos(P);
	setbulletype(bulletype);
	map.editmap(x, y, 'P');
	rescued = 0;
	money = 0;
	this->damage = damage;
	sethealth(health);
	for (int i = 0; i < 100; i++) {
		plrbullarray[i] = nullptr;
	}
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

	if (moved == true) {
		//map.editmap(returnPos().X, returnPos().Y, ' ');
		setpos(tempcord);
	}
}

void Player::shoot(BULLETDIRECTION bulletdir,int index) {
	for (int i = 0; i < 100; i++) {
		if (plrbullarray[i] == nullptr) {
			plrbullarray[i] = new Bullet(returnPos().X, returnPos().Y,BULLETOWNER::PLAYER,i,damage, bulletdir, bulletype);
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
			returnvalue = false;
			break;
		case BULLETYPE::B_B:
			returnvalue = true;
			break;
		case BULLETYPE::B_C:
			returnvalue = true;
			break;
		}
		break;
	case 'm':
		takedamage(1);
		// somehow get which enemy it is and kill it. // fix the fking movements as well, 
		returnvalue = true;
		break;
	case 'x': // traps 
		takedamage(1);
		returnvalue = true;
		break;
		// samething check player hp.
	//case 'T':
	//	returnvalue = false;
	//	break;
	//	// Movement through Changetiles
	case ' ':
		returnvalue = false;
		break;
	}
	
	return returnvalue;
}


void Player::setbulletype(BULLETYPE bulletype){
	this->bulletype = bulletype;
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

int Player::getmoney() {
	return money;
}

void Player::renderplayerbullet(Map &map) {
	for (int i = 0; i < 100; i++) {
		if (plrbullarray[i] != nullptr) {
			if (plrbullarray[i]->getstatus() == true) {
				map.editmap(plrbullarray[i]->returnPos().X, plrbullarray[i]->returnPos().Y, ' ');
				delete plrbullarray[i];
				plrbullarray[i] = nullptr;
			}
			else {
				plrbullarray[i]->movebullet(map);
				map.editmap(plrbullarray[i]->returnPos().X, plrbullarray[i]->returnPos().Y, 'B');
			}	
		}
	}
}









