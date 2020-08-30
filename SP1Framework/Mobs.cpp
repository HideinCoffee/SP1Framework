#include "mobs.h"

Mobs::Mobs(int xpos,int ypos,int index,int damage,int health,bool canshoot, bool trackplayermode,MOVEMENTDIRECTION &mobdirection):Entity(health, true, 0, 0)
{
	COORD mob;
	mob.X = xpos;
	mob.Y = ypos;
	setpos(mob);
	this->trackplayermode = trackplayermode;
	this->mobdirection = mobdirection;
	this->canshoot = canshoot;
	this->index = index;
	this->damage = damage;
	//Constructor for mobs
}

Mobs::~Mobs() {
	//destructor for mobs//  * * *
}//							 * P *
//							 * * * <-- like this
bool Mobs::checkmove(COORD playerpos) { // check if the mob is around the position around the player //
	bool needtomove = true;
	int i = 0;
	while (i < 3) {
		if ((playerpos.X - 1 == returnPos().X) && ((playerpos.Y-1) + i == returnPos().Y)) {
			needtomove = false;
		}
		else if ((playerpos.X + 1 == returnPos().X) && ((playerpos.Y-1) + i) == returnPos().Y) {
			needtomove = false;
		}
		if ((playerpos.X == returnPos().X) && (playerpos.Y + 1 == returnPos().Y)) {
			needtomove = false;
		}
		else if ((playerpos.X == returnPos().X) && (playerpos.Y - 1 == returnPos().Y)) {
			needtomove = false;
		}
		i++;
	}
	return needtomove;
}

void Mobs::move(MOVEMENTDIRECTION &movementdir, COORD playerpos, Map& map) {
	if (trackplayermode == true) {
		trackplayer(playerpos,map);
	}
	else {
		controlledmovement(map);
	}
}

void Mobs::trackplayer(COORD playerpos, Map& map) { // make it so that if the player contact    // make it so that the mob will explode yes.
	
	int playerx = playerpos.X;
	int playery = playerpos.Y;
	bool moved = false;
	COORD mob;
	mob.X = returnPos().X;
	mob.Y = returnPos().Y;
	if (checkmove(playerpos) == true) {
		if ((playerx > mob.X) && (movementcollide(map, mob.X + 1, mob.Y) == false)) { // right 
			mob.X += 1;
			moved = true;
		}
		else if ((playerx != mob.X) && (movementcollide(map, mob.X - 1, mob.Y) == false)) { // left
			mob.X -= 1;
			moved = true;
		}
		if ((playery > mob.Y) && (movementcollide(map, mob.X, mob.Y + 1) == false)) { // down
			mob.Y += 1;
			moved = true;
		}
		else if ((playery != mob.Y) && (movementcollide(map, mob.X, mob.Y - 1) == false)) { //up
			mob.Y -= 1;
			moved = true;
		}
		if (moved == true) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			setpos(mob);
			map.editmap(mob.X,mob.Y, 'm');
		}	
	}
}

void Mobs::controlledmovement(Map& map) { 
	bool moved = false;
	COORD mp = { 0,0 };
	if (getalive() == true) {
		mp = returnPos();

		switch (mobdirection.UP) {
		case true:
			if ((movementcollide(map, mp.X, mp.Y - 1) == false) && (getalive() == true)) { // move up
					mp.Y--;
					moved = true;
			}

			else {
				mobdirection.UP = false;
				mobdirection.DOWN = true;
			}
			break;
		}
		switch (mobdirection.DOWN) {
		case true:
			if ((movementcollide(map, mp.X, mp.Y + 1) == false) && (getalive() == true)) {
					mp.Y++;
					moved = true;
			}
			break;
		}
		switch (mobdirection.LEFT) {
		case true:
			if ((movementcollide(map, mp.X - 1, mp.Y) == false) && (getalive() == true)) {
				mp.X -= 1;
				moved = true;
			}
			else {
				mobdirection.LEFT = false;
				mobdirection.RIGHT = true;
			}
			break;
		}
		switch (mobdirection.RIGHT) {
		case true:
			if ((movementcollide(map, mp.X + 1, mp.Y) == false) && (getalive() == true)) {
				mp.X++;
				moved = true;
			}
			else {
				mobdirection.RIGHT = false;
				mobdirection.LEFT = true;
			}
			break;
		}

		if (moved == true) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			setpos(mp);
			map.editmap(mp.X, mp.Y, 'm');
		}
	}
}


void Mobs::shoot(BULLETDIRECTION bulletdir,int index) {
	//left blank cuz mobs are unable to shoot for now (if there is time implement shooting for mobs) probably not
}

bool Mobs::movementcollide(Map& map, int x, int y) {
	bool returnvalue = false;
	switch (map.getchar(x, y)) {
	case '#':
		returnvalue = true;
		break;
	case ' ':
		returnvalue = false;
		break;
	case '!':
		returnvalue = true;
		break;
	case '$':
		returnvalue = false;
		break;
	case 'm':
		returnvalue = true;
		break;
	case 'x':
		returnvalue = false;
		break;
	case 'B':
		for (int i = 0; i < 20; i++) {
			if (enemyarray[i] != nullptr) {
				if ((enemyarray[i]->returnPos().X == x) && (enemyarray[i]->returnPos().Y == y))
					//	enemyarray[i]->takedamage(4);
					continue;
				if (enemyarray[i]->getalive() == false) {
					delete enemyarray[i];
					enemyarray[i] = nullptr;
				}
			}
		}
		returnvalue = false;
		break;
	}
	return returnvalue;
	if (playerarray[0] != nullptr)
		if (checkmove(playerarray[0]->returnPos()) == false) {
			trackplayermode = true;
			}
}


void Mobs::AOEdamage(COORD playerpos){

}

int Mobs::getdamage() {
	return damage;
}
