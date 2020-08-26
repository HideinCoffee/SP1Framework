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

    if ((playerarray[0]->getY() > 20) && (playerarray[0]->getY() < 150 -20)) { // offset y
        g_sChar.offset.Y = playerarray[0]->getY() - 20;
    }

    for (int row = 0; row < 40; row++) {
        for (int col = 0; col < 65; col++) {
			switch (getmaptile(map, col + g_sChar.offset.X, row + g_sChar.offset.Y, g_sChar)) {
				case MAPTILES::BULLET:
					g_Console.writeToBuffer(col*2, row, "  ", 0x99);
					break;
				case MAPTILES::COIN:
					g_Console.writeToBuffer(col*2, row, "  ", 0xEE);
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
					g_Console.writeToBuffer(col*2, row, "  ", 0xff);
					break;
				case MAPTILES::TRAP:
					g_Console.writeToBuffer(col*2, row, "  ", 0x55);
					break;
			}
        }
    }
}

// game screen e.g x 130 height 40 
// ammount pixels can print is 130/2 = 65 
// ammount pixels can print for height shall stay the same = 40
// to find the center of x u do 65/2 == 33 always round up 



