#pragma once
#include "position.h"
#include "Entity.h"
class Bullet
{
private:
//	int rdistance;
	Position position;
	BULLETDIRECTION bulletdirection;
	BULLETYPE bulletype;
	int damage;
	bool terminate;
public:
	Bullet(int x, int y, BULLETDIRECTION bulletdirection,BULLETYPE bulletype);
	~Bullet();
	//set/get direction
	BULLETDIRECTION getdirection();


	// set bulletype player enemy etc
	//set position
	void setx(int x);
	void sety(int y);
	void setpos(COORD bulletposition);

	//getx and y
	COORD returnPos();

	// set bullet drop 
	//void setrdistance(int distance);
//	int getrdistance();
	void movebullet(Map &map);

	//check 
	//bool bulletcheck();
	// getstatus
	bool getstatus();
	//setstatus
	void setstatus(bool status);

	bool bulletcollide(Map& map, int x, int y);
};

