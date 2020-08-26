#include "Bullet.h"

Bullet::Bullet(int x, int y, BULLETDIRECTION bulletdir,BULLETYPE bullettp) {
	COORD bulletpos;
	bulletpos.X = x;
	bulletpos.Y = y;
	setpos(bulletpos);
	bulletdirection = bulletdir;
	switch (bullettp) {
	case BULLETYPE::B_B: // boss bullet 
		rdistance = 30;
		break;
	case BULLETYPE::B_C: // corona bullet
		rdistance = 30;
		break;
	case BULLETYPE::B_P: // player bullet
		rdistance = 30;
		break;
	//case BULLETYPE::B_T: // trap bullet
	//	rdistance = 30;
	//	break;
	}
}
	
Bullet::~Bullet() {
	// destructor left blank for now.
}

void Bullet::setpos(COORD bulletpos) {
	position.setPos(bulletpos);
}
int Bullet::getx() {
	return position.getX();
}

int  Bullet::gety() {
	return position.getY();
}
COORD Bullet::returnpos() {
	return position.returnPos();
}
void Bullet::setrdistance(int distance) {
	rdistance = distance;
}
void Bullet::movebullet(Map& map) {
	COORD pos;
	pos.X = getx();
	pos.Y = gety();
		switch (getdirection()) {
		case BULLETDIRECTION::B_UP:
			if (bulletcheck() == true) {
				pos.Y -= 1;
				if (collide(map, pos.X, pos.Y) == false) {
					map.editmap(getx(), gety(), '@');
					rdistance -= 1;
					setpos(pos);
				}
			}
			break;
		case BULLETDIRECTION::B_DOWN:
			if (bulletcheck() == true){
				pos.Y += 1;
				if (collide(map, pos.X, pos.Y) == false) {
					map.editmap(getx(), gety(), '@');
					rdistance -= 1;
					setpos(pos);
				}
			}
			else
				setstatus(true);
			break;
		case BULLETDIRECTION::B_LEFT:
			if (bulletcheck() == true) {
				pos.X -= 1;
				if (collide(map, pos.X, pos.Y) == false) {
					map.editmap(getx(), gety(), '@');
					rdistance -= 1;
					setpos(pos);
				}
			}
			else
				setstatus(true);
			break;
		case BULLETDIRECTION::B_RIGHT:
			if (bulletcheck() == true) {
				pos.X += 1;
				if (collide(map, pos.X, pos.Y) == false) {
					map.editmap(getx(), gety(), '@');
					rdistance -= 1;
					setpos(pos);
				}
				
			}
			else
				setstatus(true);
			break;
		}
}

BULLETDIRECTION Bullet::getdirection() {
	return bulletdirection;
}

int Bullet::getrdistance() {
	return rdistance;
}
bool Bullet::bulletcheck() {
	if (rdistance > 0)
		return true;
	else
		return false;
}

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


bool Bullet::collide(Map& map, int x, int y) {
	bool returnvalue = false;
	switch (map.getchar(x,y)){
		case '@': // path
			returnvalue = false;
			break;
		case '#': // wall
			setstatus(true);
			returnvalue = true;
			break;
		case 'B': // other bullets //check whose bullet
			//setstatus(true);
			returnvalue = false;
			break;
		case '!': // npc // kill npc
			setstatus(true);
			returnvalue = true;
			break;
		case 'm': // monster //damage monster 
			setstatus(true);
			returnvalue = true;
			break;
		case 'x': //traps //damage traps
			setstatus(true);
			returnvalue = false;
			break;
	}
	return returnvalue;
}





