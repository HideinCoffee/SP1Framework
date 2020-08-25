#include "mobs.h"

Mobs::Mobs(int x, int y,char symbol)
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

void Mobs::move(MOVEMENTDIRECTION movementdir,COORD pos,Map &map){
	if (needtomove == true) {
		int playerx = pos.X;
		int playery = pos.Y;
		COORD mob;
		mob.X = getX();
		mob.Y = getY();
		if ((playerx > mob.X) && (map.isoccupied(mob.X + 1, mob.Y) == false)) {
			mob.X += 1;
		}
		else if ((playerx != mob.X) && (map.isoccupied(mob.X - 1, mob.Y) == false)) {
			mob.X -= 1;
		}
		if ((playery > mob.Y) && (map.isoccupied(mob.X, mob.Y + 1) == false)) {
			mob.Y += 1;
		}
		else if ((playery != mob.Y) && (map.isoccupied(mob.X, mob.Y - 1) == false)) {
			mob.Y -= 1;
		}
		needtomove = false;
		setpos(mob);
	}

	//randomised mob movement section
//	bool mobMove = false;
//	time_t now = time(0);
}

void Mobs::shoot(BULLETDIRECTION bulletdir) {

}

void Mobs::collide(Map &map) {
	
}

void Mobs::damage(int x) {

}
