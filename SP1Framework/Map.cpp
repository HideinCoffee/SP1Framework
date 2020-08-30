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
//	std::ifstream maps;
//	std::string line;
//	char symbol;
//
//	MOVEMENTDIRECTION movementdirectionslotmap;
//	BULLETDIRECTION bulletdirectionslotmap;
//	BULLETYPE bulletypeslotmap;
//	std::ostringstream ss;
//	std::string str;
//	int trapcounter = 0;
//	int mobcounter = 0;
//
//
//	maps.open(pathway);
//	if (maps.is_open() == true) {
//		int row = 0;
//		while (std::getline(maps, line)) {
//			//depending on the object the descr will change
//			char descr1 = 0; // movement direction up down left right 1 up 2 down 3 left 4 right
//			char descr2 = 0; // bullet direction  1 up 2 down 3 left 4 right 
//			char descr3 = 0; // //bulletype
//			int health = 0;
//			int movenum = 0;
//			int damage = 0;
//			int col = 0;
//			movementdirectionslotmap.UP = false;
//			movementdirectionslotmap.DOWN = false;
//			movementdirectionslotmap.LEFT = false;
//			movementdirectionslotmap.RIGHT = false;
//			
//			std::stringstream ss(line);
//			while (std::getline(ss, str, ',')) {
//				for (unsigned int i = 0; i < str.length(); i++) {
//					switch (i) {
//					case 0:
//						maparray[row][col] = str[i];
//						symbol = str[i];
//						break;
//					case 1:
//						descr1 = str[i];
//						break;
//					case 2:
//						descr2 = str[i];
//						break;
//					case 3:
//						descr3 = str[i];
//						break;
//					}
//				}
//				switch (symbol) {
//				case 'x': // trap: symbol->bulletype ->bulletdirection->damage->
//					switch (descr3) {
//					case 0:
//						break;
//					case 1:
//						damage = 2;
//						break;
//					case 2:
//						damage = 4;
//						break;
//					case 3:
//						damage = 6;
//						break;
//					case 4:
//						damage = 8;
//						break;
//					}
//					switch (descr2) {
//					case '0': // up
//						break;
//					case '1': // up
//						switch (descr1) { // 0 bulletrap
//						case 0:
//							traparray[trapcounter] = new Trap(col, row, damage, BULLETDIRECTION::B_UP, BULLETYPE::B_T, true, true, 1);
//							trapcounter++;
//							break;
//						}
//						break;
//					case '2': // down
//						switch (descr1) { // 0 bulletrap
//						case 0:
//							traparray[trapcounter] = new Trap(col, row, damage, BULLETDIRECTION::B_DOWN, BULLETYPE::B_T, true, true, 1);
//							trapcounter++;
//							break;
//						}
//						break;
//					case '3': //left
//						switch (descr1) { // 0 bulletrap
//						case 0:
//							traparray[trapcounter] = new Trap(col, row, damage, BULLETDIRECTION::B_LEFT, BULLETYPE::B_T, true, true, 1);
//							trapcounter++;
//							break;
//						}
//						break;
//					case '4': // right
//						switch (descr1) { // 0 bulletrap
//						case 0:
//							traparray[trapcounter] = new Trap(col, row, damage, BULLETDIRECTION::B_RIGHT, BULLETYPE::B_T, true, true, 1);
//							trapcounter++;
//							break;
//						}
//						break;
//					}
//				break;
//
//				case 'm':  // symbol -> direction -> health -> damage;
//					switch (descr2) { // health 
//						case '0':
//							break;
//						case '1':
//							health = 10;
//							break;
//						case '2':
//							health = 20;
//							break;
//						case '3':
//							health = 30;
//							break;
//						case '4':
//							health = 40;
//							break;
//						case '5':
//							health = 50;
//							break;
//						case '6':
//							health = 60;
//							break;
//						case '7':
//							health = 70;
//							break;
//						case '8':
//							health = 80;
//							break;
//						case '9':
//							health = 90;
//							break;
//						}
//					switch (descr3) { // damage
//					case '0':
//						break;
//					case '1':
//						damage = 1;
//						break;
//					case '2':
//						damage = 2;
//						break;
//					case '3':
//						damage = 3;
//						break;
//					case '4':
//						damage = 4;
//						break;
//					case '5':
//						damage = 5;
//						break;
//					case '6':
//						damage = 6;
//						break;
//					case '7':
//						damage = 7;
//						break;
//					case '8':
//						damage = 8;
//						break;
//					case '9':
//						damage = 9;
//						break;
//					}
//
//					switch (descr1) {
//					case '0':
//						break;
//					case '1':
//						movementdirectionslotmap.UP = true;
//						break;
//					case '2':
//						movementdirectionslotmap.DOWN = true;
//						break;
//					case '3':
//						movementdirectionslotmap.LEFT = true;
//						break;
//					case'4':
//						movementdirectionslotmap.RIGHT = true;
//						break;
//					}
//					
//					health = descr2;
//					damage = descr3;
//					enemyarray[mobcounter] = new Mobs(col, row, mobcounter, damage, health, true, false, movementdirectionslotmap);
//					mobcounter++;
//					break;
//				}
//				col++;
//				break;
//			}
//			row++;
//		}
//		return true;
//	}
//	return false;
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





