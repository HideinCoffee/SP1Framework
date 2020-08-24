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
			if ((bulletcheck() == true) && (map.isoccupied(pos.X, pos.Y - 1) == false)) {
				replace(map, pos.X, pos.Y);
				pos.Y -= 1;
				rdistance -= 1;
				setpos(pos);
			}
			else
				setstatus(true);
			break;
		case BULLETDIRECTION::B_DOWN:
			if ((bulletcheck() == true) && (map.isoccupied(pos.X, pos.Y + 1) == false)) {
				replace(map, pos.X, pos.Y);
				pos.Y += 1;
				rdistance -= 1;
				setpos(pos);
			}
			else
				setstatus(true);
			break;
		case BULLETDIRECTION::B_LEFT:
			if ((bulletcheck() == true) && (map.isoccupied(pos.X - 1, pos.Y) == false)) {
				replace(map, pos.X, pos.Y);
				pos.X -= 1;
				rdistance -= 1;
				setpos(pos);
			}
			else
				setstatus(true);
			break;
		case BULLETDIRECTION::B_RIGHT:
			if ((bulletcheck() == true) && (map.isoccupied(pos.X + 1, pos.Y) == false)) {
				replace(map, pos.X, pos.Y);
				pos.X += 1;
				rdistance -= 1;
				setpos(pos);
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
void Bullet::replace(Map &map,int x,int y) {
	map.maparray[y][x] = '@';
}

bool Bullet::getstatus() {
	return terminate;
}
void Bullet::setstatus(bool status) {
	terminate = status;
}







