#include "player.h"
#include "map.h"
Player::Player(Map& map, BULLETYPE bulletype, int index,int x, int y,int health,int damage) :Entity(health,true,0,0) {
	COORD P;
	P.X = x;
	P.Y = y;
	setpos(P);
	setbulletype(bulletype);
	rescued = 0;
	money = 0;
	this->damage = damage;
	sethealth(health);
	this->index = index;
	for (int i = 0; i < 100; i++) {
		plrbullarray[i] = nullptr;
	}
}

void Player::move(MOVEMENTDIRECTION& movementdir, COORD pos, Map& map) {
	COORD tempcord = pos;
	bool moved = false;
	if (getalive() == true) {
		switch (movementdir.UP) {
		case true:
			if (movementcollide(map, tempcord.X, tempcord.Y - 1) == false) {
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
			if (movementcollide(map, tempcord.X, tempcord.Y + 1) == false) {
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
			if (movementcollide(map, tempcord.X - 1, tempcord.Y) == false) {
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
			if (movementcollide(map, tempcord.X + 1, tempcord.Y) == false) {
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
			map.editmap(returnPos().X, returnPos().Y, ' ');
			setpos(tempcord);
		}
	}
}
void Player::shoot(BULLETDIRECTION bulletdir,int index) {
	for (int i = 0; i < 100; i++) {
		if (plrbullarray[i] == nullptr) {
			plrbullarray[i] = new Bullet(returnPos().X, returnPos().Y,index, damage,BULLETOWNER::PLAYER, bulletdir, bulletype);
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
		returnvalue = false;
	case 'L':
		returnvalue = true;
		break;
	case 'H':
		if (gethealth() + 5 <= 30)
			sethealth(30);
		else
			sethealth(gethealth() + 5);
		returnvalue = false;
		break;
	case 'd':
		returnvalue = false;
		break;

	case 'm':
		for (int i = 0; i < 60; i++) {
			if (enemyarray[i] != nullptr) {
				if ((enemyarray[i]->returnPos().X == x) && (enemyarray[i]->returnPos().Y == y)) {
					takedamage(enemyarray[i]->getdamage());
				}
			}
		}
		returnvalue = false;
		break;
	case 'x': // traps 
		takedamage(1);
		returnvalue = true;
		break;
	case ' ':
		returnvalue = false;
		break;
	case 'Q':
		returnvalue = false;
		
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

int Player::getdamage() {
	return damage;
}








