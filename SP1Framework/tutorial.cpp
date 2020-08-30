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
	enemyarray[2] = new Mobs(149, 37, 2, 2, 20, false, false, mobmovement);
	enemyarray[3] = new Mobs(149, 40, 3, 2, 20, false, false, mobmovement);
	enemyarray[4] = new Mobs(149, 43, 4, 2, 20, false, false, mobmovement);
	enemyarray[5] = new Mobs(149, 46, 5, 2, 20, false, false, mobmovement);
	enemyarray[6] = new Mobs(149, 49, 6, 2, 20, false, false, mobmovement);
	enemyarray[7] = new Mobs(149, 52, 7, 2, 20, false, false, mobmovement);
	enemyarray[8] = new Mobs(149, 55, 8, 2, 20, false, false, mobmovement);
	enemyarray[9] = new Mobs(149, 58, 9, 2, 20, false, false, mobmovement);
	enemyarray[10] = new Mobs(149, 61,10, 2, 20, false, false, mobmovement);
	enemyarray[11] = new Mobs(149, 64, 11, 2, 20, false, false, mobmovement);
	enemyarray[12] = new Mobs(149, 67, 12, 2, 20, false, false, mobmovement);
	enemyarray[13] = new Mobs(149, 70, 13, 2, 20, false, false, mobmovement);
	enemyarray[14] = new Mobs(149, 73, 14, 2, 20, false, false, mobmovement);
	enemyarray[15] = new Mobs(149, 76, 15, 2, 20, false, false, mobmovement);
	enemyarray[16] = new Mobs(149, 79, 16, 2, 20, false, false, mobmovement);
	enemyarray[17] = new Mobs(149, 82, 17, 2, 20, false, false, mobmovement);
	enemyarray[18] = new Mobs(149, 85, 18, 2, 20, false, false, mobmovement);
	enemyarray[19] = new Mobs(149, 88, 19, 2, 20, false, false, mobmovement);
	enemyarray[20] = new Mobs(149, 91, 20, 2, 20, false, false, mobmovement);
	enemyarray[21] = new Mobs(149, 94, 21, 2, 20, false, false, mobmovement);
	enemyarray[22] = new Mobs(149, 97, 22, 2, 20, false, false, mobmovement);
	enemyarray[23] = new Mobs(74, 38, 23, 2, 20, false, false, mobmovement);
	enemyarray[24] = new Mobs(74, 41, 23, 2, 20, false, false, mobmovement);
	enemyarray[25] = new Mobs(74, 44, 23, 2, 20, false, false, mobmovement);
	enemyarray[26] = new Mobs(74, 47, 23, 2, 20, false, false, mobmovement);
	enemyarray[27] = new Mobs(74, 50, 23, 2, 20, false, false, mobmovement);
	enemyarray[28] = new Mobs(74, 53, 23, 2, 20, false, false, mobmovement);
	enemyarray[29] = new Mobs(74, 56, 23, 2, 20, false, false, mobmovement);
	enemyarray[30] = new Mobs(74, 59, 23, 2, 20, false, false, mobmovement);
	enemyarray[31] = new Mobs(74, 62, 23, 2, 20, false, false, mobmovement);
	enemyarray[32] = new Mobs(74, 65, 23, 2, 20, false, false, mobmovement);
	enemyarray[33] = new Mobs(74, 68, 23, 2, 20, false, false, mobmovement);
	enemyarray[34] = new Mobs(74, 71, 13, 2, 20, false, false, mobmovement);
	enemyarray[35] = new Mobs(74, 74, 13, 2, 20, false, false, mobmovement);
	enemyarray[36] = new Mobs(74, 77, 13, 2, 20, false, false, mobmovement);
	enemyarray[37] = new Mobs(74, 80, 13, 2, 20, false, false, mobmovement);
	enemyarray[38] = new Mobs(74, 83, 13, 2, 20, false, false, mobmovement);
	enemyarray[39] = new Mobs(74, 86, 13, 2, 20, false, false, mobmovement);
	enemyarray[40] = new Mobs(74, 89, 13, 2, 20, false, false, mobmovement);
	enemyarray[41] = new Mobs(74, 92, 13, 2, 20, false, false, mobmovement);
	enemyarray[42] = new Mobs(74, 95, 13, 2, 20, false, false, mobmovement);
	enemyarray[43] = new Mobs(74, 98, 13, 2, 20, false, false, mobmovement);
	mobmovement.LEFT = false;

	//THIS IS A COMMENT
}