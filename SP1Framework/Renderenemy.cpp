#include "Renderenemy.h"

void renderenemy(Map& map, Entity* enemyarray[]) {
	for (int i = 0; i < 20; i++) {
		if (enemyarray[i] != nullptr) {
			if (enemyarray[i]->getalive() == false) {
				map.editmap(enemyarray[i]->returnPos().X, enemyarray[i]->returnPos().Y, ' ');
				delete enemyarray[i];
				enemyarray[i] = nullptr;
			}
			else
				map.editmap(enemyarray[i]->returnPos().X, enemyarray[i]->returnPos().Y, enemyarray[i]->getsymbol());
		}
	}
}