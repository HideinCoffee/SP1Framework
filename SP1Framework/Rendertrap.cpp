#include "Rendertrap.h"

void rendertrap(Map& map, misc* traparray[]) {
	for (int i = 0; i < 20; i++) {
		if (traparray[i] != nullptr) {
			map.editmap(traparray[i]->returnPos().X, traparray[i]->returnPos().Y, traparray[i]->getsymbol());
		}
	}
}
