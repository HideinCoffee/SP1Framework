#include "Renderenemy.h"

void renderenemy(Map& map, Entity* entityarray[]) {
	for (int i = 1; i < 20; i++) {
		if (entityarray[i] != nullptr) {
			map.editmap(entityarray[i]->getX(), entityarray[i]->getY(), entityarray[i]->getsymbol());
		}
	}
}