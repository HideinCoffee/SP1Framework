#include "mobs.h"

Mobs::Mobs(int xpos, int ypos, int movenum, char symbol, bool trackplayermode,MOVEMENTDIRECTION &mobdirection):Entity(0, true, 'm', 0, 0)
{
	needtomove = true;
	COORD mob;
	mob.X = xpos;
	mob.Y = ypos;
	movecount = 0;
	reverse = false;
	setpos(mob);
	setsymbol(symbol);
	this->movenum = movenum;
	this->trackplayermode = trackplayermode;
	this->mobdirection = mobdirection;
	//Constructor for mobs
}

Mobs::~Mobs() {
	//destructor for mobs
}

void Mobs::checkmove(COORD pos) {
	if ((pos.X != returnPos().X) || (pos.Y != returnPos().Y)) {
		needtomove = true;
	}
	else {
		needtomove = false;
	}
}

void Mobs::move(MOVEMENTDIRECTION &movementdir, COORD playerpos, Map& map) {
	if (trackplayermode == true) {
		trackplayer(playerpos,map);
	}
	else {
		controlledmovement(map);
	}
}

void Mobs::trackplayer(COORD playerpos, Map& map) {
	if (needtomove == true) {
		int playerx = playerpos.X;
		int playery = playerpos.Y;
		bool moved = false;
		COORD mob;
		mob.X = returnPos().X;
		mob.Y = returnPos().Y;
		if ((playerx > mob.X) && (map.isoccupied(mob.X + 1, mob.Y) == false)) {
			mob.X += 1;
			moved = true;
		}
		else if ((playerx != mob.X) && (map.isoccupied(mob.X - 1, mob.Y) == false)) {
			mob.X -= 1;
			moved = true;
		}
		if ((playery > mob.Y) && (map.isoccupied(mob.X, mob.Y + 1) == false)) {
			mob.Y += 1;
			moved = true;
		}
		else if ((playery != mob.Y) && (map.isoccupied(mob.X, mob.Y - 1) == false)) {
			mob.Y -= 1;
			moved = true;
		}
		if (moved == true) {
			map.editmap(returnPos().X,returnPos().Y, ' ');
			needtomove = false;
			setpos(mob);
		}
	}
}
void Mobs::controlledmovement(Map& map) { // for some reason it renders after a while. . . fix tmr yes
	bool moved = false;
	COORD mp = returnPos();
	switch (mobdirection.UP) {
	case true:
		if (movementcollide(map, mp.X, mp.Y-1) == false) { // move up
			if (movecount < movenum) {
				mp.Y--;
				moved = true;
				movecount++;
			}
			else {
				movecount = 0;
				mobdirection.UP = false;
				mobdirection.DOWN = true;
			}
		}
		break;
	}
	switch (mobdirection.DOWN) {
	case true:
		if (movementcollide(map, mp.X, mp.Y+1) == false) {
			if (movecount < movenum) {
				mp.Y++;
				moved = true;
				movecount++;
				
			}
			else {
				movecount = 0;
				mobdirection.DOWN = false;
				mobdirection.UP = true;
			}
		}
		break;
	}
	switch (mobdirection.LEFT) {
	case true:
		if (movementcollide(map, mp.X-1, mp.Y) == false) {
			if (movecount < movenum) {
				mp.X--;
				moved = true;
				movecount++;
			}
			else {
				movecount = 0;
				mobdirection.LEFT = false;
				mobdirection.RIGHT = true;
			}
		}
		break;
	}
	switch (mobdirection.RIGHT) {
	case true:
		if (movementcollide(map, mp.X+1, mp.Y) == false) {
			if (movecount < movenum) {
				mp.X++;
				moved = true;
				movecount++;
			}
			else {
				movecount = 0;
				mobdirection.RIGHT = false;
				mobdirection.LEFT = true;
			}
		}
		break;
	}

	if (moved == true) {
		map.editmap(returnPos().X, returnPos().Y, ' ');
		setpos(mp);
		map.editmap(mp.X,mp.Y,'m');
	}
}


void Mobs::shoot(BULLETDIRECTION bulletdir) {


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
		// collide with npc 
		// make it capture the npc // if theres time
		returnvalue = true;
		break;
	case '$':
		// coolide with money
		// make it steal the money? idk
		returnvalue = false;
		break;
	case 'm':
		// collide with enemy
		// ntg happens
		returnvalue = true;
		break;
		// collide with trap  
	case 'x':
		//take damage
		returnvalue = false;
		break;
	case 'P':
		returnvalue = true;
		break;
	}
	return returnvalue;
}

void Mobs::damage(int x) {
	// mob take damage. 
}
