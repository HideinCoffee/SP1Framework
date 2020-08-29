#include "Map.h"
#include "global.h"
#include "misc.h"
#include "trap.h"
#include "Mobs.h"
#include "Entity.h"

Map::Map():maparray{0} {

	for (int row = 0; row < 150; row++) {
		for (int col = 0; col < 150; col++) {
			maparray[row][col] = ' ';
		}
	}
}

Map::~Map(){
	//this is left blank intentionally
}


COORD Map::movecamera(int direction, COORD playerpos) {
	COORD pos = playerpos;

	switch (direction) {
	case 0:
		break;
	case 1: // move up 
		pos.Y -= 1;
		break;
	case 2: // move down
		pos.Y += 1;
		break;
	case 3: // move left
		pos.X -= 1;
		break;
	case 4: // move right
		pos.X += 1;
		break;
	}
	return pos;
}

bool Map::slotmap(std::string filename, Console &g_Console)
{
	std::string pathway = "maps//" + filename;
	std::ifstream map;
	std::string line;
	//char colvalue;
	map.open(pathway);
	if (map.is_open() == true){
		int row = 0;
		while (std::getline(map, line)){
			int col = 0;
			for (int datacol = 0; datacol < 150*2-1; datacol++) {
				switch (line[datacol]) {
				case ',':
					break;
				default:
					maparray[row][col] = line[datacol];
					col++;
					break;
				}
			}
			row++;
		}
		return true;
	}
	else {
		return false;
	}
}
//bool Map::slotmap(std::string filename, Console& g_Console)
//{
//	std::string pathway = "maps//" + filename;
//	std::ifstream map;
//	std::string line;
//	char symbol;
//	//depending on the object the descr will change
//	char descr1 = 0; // movement direction up down left right 1 up 2 down 3 left 4 right
//	char descr2 = 0; // bullet direction  1 up 2 down 3 left 4 right 
//	char descr3 = 0; // 
//
//	std::ostringstream ss;
//	std::string str;
//	MOVEMENTDIRECTION movementdir;
//	BULLETDIRECTION bulletdirection;
//	BULLETYPE bulletype;
//	int trapcounter = 0;
//	int mobcounter =  0;
//	
//	map.open(pathway);
//	if (map.is_open() == true) {
//		int row = 0;
//		while (std::getline(map, line)) {
//			int col = 0;
//			for (int datacol = 0; datacol < 150 * 2 - 1; datacol++) {
//				switch (line[datacol]) {
//				case ',':
//					break;
//				default:
//					ss.str("");
//					ss << line[datacol];
//					if (ss.str().length() > 1) {
//						symbol = ss.str()[0];
//					}
//					else {
//						symbol = ss.str()[0];
//						descr1 = ss.str()[1];
//						descr2 = ss.str()[2];
//						switch (descr1) { // movementdirection
//						case '0':
//							break;
//						case '1':
//							movementdir.UP = true;
//							break;
//						case '2':
//							movementdir.DOWN = true;
//							break;
//						case '3':
//							movementdir.LEFT = true;
//							break;
//						case '4':
//							movementdir.RIGHT = true;
//							break;
//						}
//						switch (descr2) { // bulletdirection
//						case '0':
//							break;
//						case '1':
//							bulletdirection = BULLETDIRECTION::B_UP;
//							break;
//						case '2':
//							bulletdirection = BULLETDIRECTION::B_DOWN;
//							break;
//						case '3':
//							bulletdirection = BULLETDIRECTION::B_LEFT;
//							break;
//						case '4':
//							bulletdirection = BULLETDIRECTION::B_RIGHT;
//							break;
//						}
//					}
//					switch (symbol) {
//					case 'x': // trap
//						traparray[trapcounter] = new Trap(col,row,descr1,descr2,true,true,1);
//						trapcounter++;
//						break;
//					case 'm': // mob 
//						enemyarray[mobcounter];
//						mobcounter++;
//						break;
//
//					}
//					
//					maparray[row][col] = line[datacol];
//					col++;
//					break;
//				}
//			}
//			row++;
//		}
//	}
//}


void Map::editmap(int x, int y, char toreplace) {
	maparray[y][x] = toreplace;
}


bool Map::checkread() {
	return read;
}
void Map::changeread(bool status) {
	read = status;
}

bool Map::isoccupied( int x, int y) {
	if (maparray[y][x] == '#') //&& (maparray[y][x] != 'm'))
	{
		return true;
	}
	else
		return false;
}

char Map::getchar(int x, int y) {
	char chartoreturn = maparray[y][x];
	return chartoreturn;
}

//char* Map::getmaparray() {
//	char* ptrtomap = *maparray;
//	return ptrtomap;
//}




