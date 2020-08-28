#include "Rendermap.h"
MAPTILES getmaptile(Map& map, int x, int y,SGameChar &g_sChar) {
	MAPTILES returnvalue = MAPTILES::DEFAULT;
	char mapchar =map.getchar(x, y);
	switch (mapchar) {
	case '#':
		returnvalue = MAPTILES::WALL;
		break;
	case ' ':
		returnvalue = MAPTILES::PATH;
		break;
	case 'B':
		returnvalue = MAPTILES::BULLET;
		break;
	case 'R':
		returnvalue = MAPTILES::BULLET1;
		break;
	case 'm':
		returnvalue = MAPTILES::MOB;
		break;
	case '!':
		returnvalue = MAPTILES::NPC;
		break;
	case '$':
		returnvalue = MAPTILES::COIN;
		break;
	case 'x':
		returnvalue = MAPTILES::TRAP;
		break;
	//case 'T':
	//	returnvalue = MAPTILES::CHANGEPAD;
	//	break;
	}
	return returnvalue;
}



void rendermap(Console &g_Console,Map &map,SGameChar &g_sChar,Entity* playerarray[]) {
    if (map.checkread() == false) {
        if (map.slotmap("map.csv", g_Console) == true) {
            map.changeread(true);
        }
    }
    if ((playerarray[0]->getX() > 33) && (playerarray[0]->getX() < 150-33)) { // offset x
        g_sChar.offset.X = playerarray[0]->getX() - 33;
    }

    if ((playerarray[0]->getY() > 18) && (playerarray[0]->getY() < 150 -18)) { // offset y
        g_sChar.offset.Y = playerarray[0]->getY() - 18;
    }

    for (int row = 0; row < 35; row++) {
        for (int col = 0; col < 65; col++) {
			switch (getmaptile(map, col + g_sChar.offset.X, row + g_sChar.offset.Y, g_sChar)) {
				case MAPTILES::BULLET:
					g_Console.writeToBuffer(col*2, row, "  ", 0x99);
					break;
				case MAPTILES::BULLET1:
					g_Console.writeToBuffer(col*2, row, "  ", 0x44);
					break;
				case MAPTILES::COIN:
					g_Console.writeToBuffer(col*2, row, "  ", 0x66);
					break;
				case MAPTILES::MOB:
					g_Console.writeToBuffer(col*2, row, "  ", 0xCC);
					break;
				case MAPTILES::WALL:
					g_Console.writeToBuffer(col*2, row, "  ", 0x00);
					break;
				case MAPTILES::NPC:
					g_Console.writeToBuffer(col*2, row, "  ", 0x22);
					break;
				case MAPTILES::PATH:
					g_Console.writeToBuffer(col*2, row, "  ", 0x88);
					break;
				case MAPTILES::TRAP:
					g_Console.writeToBuffer(col*2, row, "  ", 0x55);
					break;
				//case MAPTILES::CHANGEPAD:
				//	g_Console.writeToBuffer(col* 2, row,"  ", 0xBB);
				//	break;
			}
        }
    }
}

// game screen e.g x 130 height 40 
// ammount pixels can print is 130/2 = 65 
// ammount pixels can print for height shall stay the same = 40
// to find the center of x u do 65/2 == 33 always round up 



