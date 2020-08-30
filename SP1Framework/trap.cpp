#include "trap.h"
#include "position.h"

Trap::Trap(int posx, int posy,int damage
	, BULLETDIRECTION bulletdirection,
	BULLETYPE bulletype, bool canshoot = false, bool activated = true, int speed = 1)
	: misc(MISCTYPE::TRAP, posx, posy){
	this->canshoot = canshoot;
	this->bulletdirection = bulletdirection;
	this->bulletype = bulletype;
	this->activated = activated;
	this->speed = speed;
	this->damage = damage;
	
	for (int i = 0; i < 100; i++)
	{
		if (trapbulletarray[i] != nullptr)
			trapbulletarray[i] = nullptr;
	}
}

Trap::~Trap() {
	//leftblankfornow
}

void Trap::shoot(Map& map) {
	for (int i = 0; i < 100; i++) {
		if (trapbulletarray[i] == nullptr){ 
			trapbulletarray[i] = new Bullet(returnPos().X,returnPos().Y,i,damage,BULLETOWNER::TRAP,bulletdirection,bulletype);
			break;
		}
	}
}


void Trap::renderbullet(Map& map) {
	for (int i = 0; i < 100; i++) {
		if (trapbulletarray[i] != nullptr) {
			if (trapbulletarray[i]->getstatus() == true) {
				map.editmap(trapbulletarray[i]->returnPos().X, trapbulletarray[i]->returnPos().Y, ' ');
				delete trapbulletarray[i];
				trapbulletarray[i] = nullptr;
			}
			else {
				map.editmap(trapbulletarray[i]->returnPos().X, trapbulletarray[i]->returnPos().Y, ' ');
				trapbulletarray[i]->movebullet(map);
				map.editmap(trapbulletarray[i]->returnPos().X, trapbulletarray[i]->returnPos().Y, 'Q');
			}
		}
	}
}


Bullet* Trap::returntrpbullarray() {
	Bullet* ptrtoarray = *trapbulletarray;
	return ptrtoarray;
}