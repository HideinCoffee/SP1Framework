#include "Bullet.h"

Bullet::Bullet(int x, int y,BULLETDIRECTION bulletdirection,BULLETYPE bulletype) {
	COORD bulletpos;
	bulletpos.X = x;
	bulletpos.Y = y;
	setpos(bulletpos);
	this->bulletdirection = bulletdirection;
	switch (bulletype) {
	case BULLETYPE::B_B: // boss bullet 
		damage = 5;
		this->bulletype = bulletype;
		break;
	case BULLETYPE::B_C: // corona bullet
		damage = 1;
		this->bulletype = bulletype;
		break;
	case BULLETYPE::B_P: // player bullet
		damage = 1;
		this->bulletype = bulletype;
		break;
	}
}
	
Bullet::~Bullet() {
	// destructor left blank for now.
}

void Bullet::setpos(COORD bulletposition) {
	position.setPos(bulletposition);
}

COORD Bullet::returnPos() {
	return position.returnPos();
}
//void Bullet::setrdistance(int distance) {
//	rdistance = distance;
//}
void Bullet::movebullet(Map& map) {
	COORD pos;
	pos.X = returnPos().X;
	pos.Y = returnPos().Y;
	switch (getdirection()) {
	case BULLETDIRECTION::B_UP:
		pos.Y -= 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) { // if it is true it means the bullet is getting destroyed. (Seems like it only fires if it's 1) next to a wall, and 2) firing up)
			map.editmap(returnPos().X, returnPos().Y, ' ');
			//rdistance -= 1;
			setpos(pos);
		}
		else
			setstatus(true);
		break;
	case BULLETDIRECTION::B_DOWN:
		pos.Y += 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			//rdistance -= 1;
			setpos(pos);
		}
		else
			setstatus(true);
		break;
	case BULLETDIRECTION::B_LEFT:
		pos.X -= 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			//rdistance -= 1;
			setpos(pos);
		}

		else
			setstatus(true);
		break;
	case BULLETDIRECTION::B_RIGHT:
		//if (bulletcheck() == true) {
		pos.X += 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			//rdistance -= 1;
			setpos(pos);

		}
		else if (bulletcollide(map, pos.X, pos.Y) == false){

		}
		else
			setstatus(true);
		break;
	}
}

BULLETDIRECTION Bullet::getdirection() {
	return bulletdirection;
}

//int Bullet::getrdistance() {
//	return rdistance;
//}
//bool Bullet::bulletcheck() {
//	if (rdistance > 0)
//		return true;
//	else
//		return false;
//}

void Bullet::setx(int x){
	position.setX(x);
}

void Bullet::sety(int y){
	position.setY(y);
}

bool Bullet::getstatus() {
	return terminate;
}

void Bullet::setstatus(bool status) {
	terminate = status;
}


bool Bullet::bulletcollide(Map& map, int x, int y) {
	bool returnvalue = false;
	switch (map.getchar(x,y)){
		case ' ': // path
			returnvalue = false;
			break;
		case '#': // wall
			setstatus(true);
			returnvalue = true;
			break;
		case '!': // npc // kill npc
			setstatus(true);
			returnvalue = false;
			break;
		case 'm': // monster //damage monster 
			setstatus(true);
			returnvalue = true;
			break;
		case 'x': //traps //damage traps
			setstatus(true);
			returnvalue = true;
			break;
		case '$':
			setstatus(true);
			returnvalue = true;
		//case 'T':
		//	setstatus(true);
		//	returnvalue = true;
	}
	return returnvalue;
}





