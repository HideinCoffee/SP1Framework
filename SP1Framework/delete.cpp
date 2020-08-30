#include "delete.h"
#include "global.h"
void reload() {
	delete playerarray[0];
	playerarray[0] = nullptr;
	for (int i = 0; i < 60; i++) {
		delete enemyarray[i];
		enemyarray[i] = nullptr;
		delete traparray[i];
		traparray[i] = nullptr;
	}
}