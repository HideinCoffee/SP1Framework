#include "mobs.h"

Mobs::Mobs(int x, int y)
{
	COORD mob;
	mob.X = x;
	mob.Y = y;
	setpos(mob);
	//Constructor for mobs
}

Mobs::~Mobs()
{
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

void Mobs::move(MOVEMENTDIRECTION movementdir,COORD pos)
{
	if (needtomove == true) {
		int playerx = pos.X;
		int playery = pos.Y;
		COORD mob;
		mob.X = getX();
		mob.Y = getY();
		if (playerx > mob.X)
			mob.X += 1;
		else if (playerx != mob.X)
			mob.X -= 1;
		if (playery > mob.Y)
			mob.Y += 1;
		else if (playery != mob.Y)
			mob.Y -= 1;
		needtomove = false;
		setpos(mob);
	}
	//randomised mob movement section
//	bool mobMove = false;
//	time_t now = time(0);
}
