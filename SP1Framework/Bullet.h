#pragma once
#include "position.h"
#include "entity.h"
enum class BULLETOWNER {
	PLAYER,
	TRAP,
	MOB // give the mobs a name ffs later
};

class Bullet
{
	
private:
	BULLETOWNER bulletowner;
	Position position;
	BULLETDIRECTION bulletdirection;
	//BULLETYPE bulletype;
	int index;
	int damage;
	bool terminate;
	double delay;
public:
	Bullet(int x, int y,int index,int damage, BULLETOWNER bulletowner,BULLETDIRECTION bulletdirection,BULLETYPE bulletype);
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

	BULLETOWNER getbulletowner();
};

