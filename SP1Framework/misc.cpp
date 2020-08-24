#include "misc.h"
#include "entity.h"
#include "global.h"

misc::misc() {
	int coin = 0;
	if ((entityarray[0]->getX() << entityarray[0]->getY()) == '$')
	{
		coin ++ ;
		(entityarray[0]->getX() << '@' << entityarray[0]->getY());
	}
}
misc::~misc() {
	//deconstructor 
}
