#pragma once
#include "misc.h"
#include "Global.h"

class Trap : public misc {
private :
	BULLETYPE bulletype;
	COORD position1;
public :
	void setpos(COORD pos);
	Trap(Map& map, BULLETYPE bulletype, int x, int y);
	void shoot(BULLETDIRECTION bulletdirection);
	//setter
	void setbulletype(BULLETYPE bulletype);
	//getter
	BULLETYPE getbulletype();
};