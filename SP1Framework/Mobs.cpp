#include "mobs.h"

Mobs::Mobs(int x, int y, char symbol) :Entity(0,true, 'm')
{
	needtomove = true;
	COORD mob;
	mob.X = x;
	mob.Y = y;
	setpos(mob);
	setsymbol(symbol);
	//Constructor for mobs
}

Mobs::~Mobs(){
	//destructor for mobs
}

void Mobs::checkmove(COORD pos) {
	if ((pos.X != getX()) || (pos.Y != getY())){
		needtomove = true;
	}
	else {
		needtomove = false;
	}
}

void Mobs::move(MOVEMENTDIRECTION movementdir, COORD pos, Map& map) { // do the player collide with mob thing 
	if (needtomove == true) {
		int playerx = pos.X;
		int playery = pos.Y;
		bool moved = false;
		COORD mob;
		mob.X = getX();
		mob.Y = getY();
		map.editmap(pos.X, pos.Y, '@');
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
			needtomove = false;
			setpos(mob);
		}
	}
}

void Mobs::trackplayer(COORD pos, Map& map) {
	/*if (needtomove == true) {
		int playerx = pos.X;
		int playery = pos.Y;
		bool moved = false;
		COORD mob;
		mob.X = getX();
		mob.Y = getY();
		if ((playerx > mob.X) && (map.isoccupied(mob.X + 1, mob.Y) == false)) {
			mob.X += 1;
			map.editmap(pos.X, pos.Y, '@');
			moved = true;
		}
		else if ((playerx != mob.X) && (map.isoccupied(mob.X - 1, mob.Y) == false)) {
			mob.X -= 1;
			map.editmap(pos.X, pos.Y, '@');
			moved = true;
		}
		if ((playery > mob.Y) && (map.isoccupied(mob.X, mob.Y + 1) == false)) {
			mob.Y += 1;
			map.editmap(pos.X, pos.Y, '@');
			moved = true;
		}
		else if ((playery != mob.Y) && (map.isoccupied(mob.X, mob.Y - 1) == false)) {
			mob.Y -= 1;
			map.editmap(pos.X, pos.Y, '@');
			moved = true;
		}
		if (moved = true) {
			needtomove = false;
			setpos(mob);
		}
	}*/

}
//}

void Mobs::shoot(BULLETDIRECTION bulletdir) {

}

void Mobs::movementcollide(Map &map,int x, int y) {
	
// insert collide code here.
}

void Mobs::damage(int x) {
	// mob take damage. 
}
