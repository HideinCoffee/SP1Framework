#include "Renderenemy.h"

void renderenemy(Map& map, Entity* enemyarray[]) {
	for (int i = 0; i < 20; i++) {
		if (enemyarray[i] != nullptr) {
			map.editmap(enemyarray[i]->returnPos().X, enemyarray[i]->returnPos().Y,'m');
		}
	}
}




