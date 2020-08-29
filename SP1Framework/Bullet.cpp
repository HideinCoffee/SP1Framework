#include "Bullet.h"
#include "global.h"

Bullet::Bullet(int x, int y,BULLETOWNER bulletowner,int index,int damage,BULLETDIRECTION bulletdirection,BULLETYPE bulletype) {
	COORD bulletpos;
	bulletpos.X = x;
	bulletpos.Y = y;
	terminate = false;
	this->damage = damage;
	this->bulletowner = bulletowner;
	this->index = index;
	setpos(bulletpos);
	this->bulletdirection = bulletdirection;
	switch (bulletype) {
	case BULLETYPE::B_B: // boss bullet 
		this->bulletype = bulletype;
		break;
	case BULLETYPE::B_C: // corona bullet
		this->bulletype = bulletype;
		break;
	case BULLETYPE::B_P: // player bullet
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
			setpos(pos);
		}
		else
			setstatus(true);
		break;
	case BULLETDIRECTION::B_DOWN:
		pos.Y += 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			setpos(pos);
		}
		else
			setstatus(true);
		break;
	case BULLETDIRECTION::B_LEFT:
		pos.X -= 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
			setpos(pos);
		}

		else
			setstatus(true);
		break;
	case BULLETDIRECTION::B_RIGHT:
		pos.X += 1;
		if (bulletcollide(map, pos.X, pos.Y) == false) {
			map.editmap(returnPos().X, returnPos().Y, ' ');
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
			returnvalue = true;
			break;
		case '!': 
			returnvalue = false;
			break;
		case 'm': // monster //damage monster 
			switch (getbulletowner()) {
			case BULLETOWNER::MOB:
				break;
			case BULLETOWNER::TRAP:
				setstatus(true);
				break;
			case BULLETOWNER::PLAYER:
				for (int i = 0; i < 20; i ++) {
					if (enemyarray[i] != nullptr) {
						if ((enemyarray[i]->returnPos().X == x) && (enemyarray[i]->returnPos().Y == y))
							enemyarray[i]->takedamage(damage);
						break;
					}
				}
				break;
			}
			returnvalue = true;
			break;
		case 'x':
			returnvalue = true;
			break;
		case '$':
			returnvalue = true;
		case 'B':
			returnvalue = true;
		case 'Q':
			if (getbulletowner() != BULLETOWNER::TRAP) {
				
				returnvalue = false;
			}
			else {
				returnvalue = true;
			}
		case 'P':
			switch (getbulletowner()) {
			case BULLETOWNER::MOB:
				//playerarray[0]->takedamage(damage);
				returnvalue = true;
				break;
			case BULLETOWNER::PLAYER:
				returnvalue = false;
				break;
			case BULLETOWNER::TRAP:
				returnvalue = true;
				break;
			}
	}
	return returnvalue;
}

BULLETOWNER Bullet::getbulletowner()
{
	return bulletowner;
}




















