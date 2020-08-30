#include "tutorial.h"
#include "global.h"
#include "player.h"
#include "Mobs.h"
#include "trap.h"
// wanted to create a function for this so that it is efficient but not enough time. (didnt want to hardcode this) . . .
void createtutobj(Map &map) {
	//player 
	playerarray[0] = new Player(map, BULLETYPE::B_P, 0, 22, 4, 30, 2);
	MOVEMENTDIRECTION mobmovement = { false, false, false, false };

	// traps
	traparray[0] = new Trap(19, 4,3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[1] = new Trap(20, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[2] = new Trap(21, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[3] = new Trap(24, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[4] = new Trap(25, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[5] = new Trap(26, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[6] = new Trap(26, 49, 3, BULLETDIRECTION::B_UP, BULLETYPE::B_T, true, true, 1);
	traparray[7] = new Trap(27, 49, 3, BULLETDIRECTION::B_UP, BULLETYPE::B_T, true, true, 1);
	traparray[8] = new Trap(28, 49, 3, BULLETDIRECTION::B_UP, BULLETYPE::B_T, true, true, 1);
	traparray[9] = new Trap(39, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	traparray[10] = new Trap(40, 4, 3, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
	// mobs
	mobmovement.DOWN = true;
	enemyarray[0] = new Mobs(43, 5, 0, 2, 20, false, false, mobmovement);
	enemyarray[1] = new Mobs(43, 5, 1, 2, 20, false, false, mobmovement);
	mobmovement.DOWN = false;
	mobmovement.LEFT = true;
	enemyarray[2] = new Mobs(106, 37, 2, 2, 20, false, false, mobmovement);
	enemyarray[3] = new Mobs(106, 40, 3, 2, 20, false, false, mobmovement);
	enemyarray[4] = new Mobs(106, 43, 4, 2, 20, false, false, mobmovement);
	enemyarray[5] = new Mobs(106, 46, 5, 2, 20, false, false, mobmovement);
	enemyarray[6] = new Mobs(106, 49, 6, 2, 20, false, false, mobmovement);
	enemyarray[7] = new Mobs(106, 52, 7, 2, 20, false, false, mobmovement);
	enemyarray[8] = new Mobs(106, 55, 8, 2, 20, false, false, mobmovement);
	enemyarray[9] = new Mobs(106, 58, 9, 2, 20, false, false, mobmovement);
	enemyarray[10] = new Mobs(106, 61,10, 2, 20, false, false, mobmovement);
	enemyarray[11] = new Mobs(106, 64, 11, 2, 20, false, false, mobmovement);
	enemyarray[12] = new Mobs(106, 67, 12, 2, 20, false, false, mobmovement);
	enemyarray[13] = new Mobs(106, 70, 13, 2, 20, false, false, mobmovement);
	enemyarray[14] = new Mobs(106, 73, 14, 2, 20, false, false, mobmovement);
	enemyarray[15] = new Mobs(106, 76, 15, 2, 20, false, false, mobmovement);
	enemyarray[16] = new Mobs(106, 79, 16, 2, 20, false, false, mobmovement);
	enemyarray[17] = new Mobs(106, 82, 17, 2, 20, false, false, mobmovement);
	enemyarray[18] = new Mobs(106, 85, 18, 2, 20, false, false, mobmovement);
	enemyarray[19] = new Mobs(106, 88, 19, 2, 20, false, false, mobmovement);
	enemyarray[20] = new Mobs(106, 91, 20, 2, 20, false, false, mobmovement);
	enemyarray[21] = new Mobs(106, 94, 21, 2, 20, false, false, mobmovement);
	enemyarray[22] = new Mobs(106, 97, 22, 2, 20, false, false, mobmovement);
	mobmovement.LEFT = false;


}