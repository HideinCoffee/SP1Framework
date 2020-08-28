#include "Rendertrap.h"

void rendertrap(Map& map, misc* traparray[]) {
	for (int i = 0; i < 200; i++) {
		if (traparray[i] != nullptr) {
			map.editmap(traparray[i]->getx(), traparray[i]->gety(), traparray[i]->getsymbol());
		}
	}
}
