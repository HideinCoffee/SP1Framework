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
	case 'Q':
		returnvalue = MAPTILES::TRAPBULLET;
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
	case 'P':
		returnvalue = MAPTILES::PLAYER;
		break;
	case 'T':
		returnvalue = MAPTILES::TOGGLE;
		break;
	case 'H':
		returnvalue = MAPTILES::HEALTH;
		break;
	case 'A':
		returnvalue = MAPTILES::AMMO;
		break;
	case 'D':
		returnvalue = MAPTILES::DOOR;
		break;
	case 'L':
		returnvalue = MAPTILES::LAVA;
		break;
	case 'G':
		returnvalue = MAPTILES::GOAL;
		break;
	}
	return returnvalue;
}



void rendermap(Console &g_Console,Map &map,SGameChar &g_sChar,Entity* playerarray[]) {
    if (map.checkread() == false) {
        if (map.slotmap("Tutorial.csv", g_Console) == true) {
            map.changeread(true);
        }
    }
    if ((playerarray[0]->returnPos().X > 33) && (playerarray[0]->returnPos().X < 150-30)) { // offset x
        g_sChar.offset.X = playerarray[0]->returnPos().X - 33;
    }

    if ((playerarray[0]->returnPos().Y > 18) && (playerarray[0]->returnPos().Y < 150 -18)) { // offset y
        g_sChar.offset.Y = playerarray[0]->returnPos().Y - 18;
    }

    for (int row = 0; row < 35; row++) {
        for (int col = 0; col < 65; col++) {
			switch (getmaptile(map, col + g_sChar.offset.X, row + g_sChar.offset.Y, g_sChar)) {
				case MAPTILES::BULLET:
					g_Console.writeToBuffer(col*2, row, "  ", 0x99);
					break;
				case MAPTILES::TRAPBULLET:
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
				case MAPTILES::TOGGLE:
					g_Console.writeToBuffer(col * 2, row, "  ", 0x99);
					break;
				/*case MAPTILES::HEALTH:
					g_Console.writeToBuffer(col * 2, row, "H ", 0x2F);
					break;*/
				case MAPTILES::AMMO:
					g_Console.writeToBuffer(col * 2, row, "A ", 0x2F);
					break;
				case MAPTILES::DOOR:
					g_Console.writeToBuffer(col * 2, row, "D ", 0x0f);
					break;
				case MAPTILES::LAVA:
					g_Console.writeToBuffer(col * 2, row, "  ", 0xcc);
					break;
				case MAPTILES::GOAL:
					g_Console.writeToBuffer(col * 2, row, "G ", 0x0f);

			}
        }
    }
}

// game screen e.g x 130 height 40 
// ammount pixels can print is 130/2 = 65 
// ammount pixels can print for height shall stay the same = 40
// to find the center of x u do 65/2 == 33 always round up 



