#include "Map.h"

Map::Map():maparray{0} {

	for (int row = 0; row < 40; row++) {
		for (int col = 0; col < 160; col++) {
			maparray[row][col] = ' ';
		}
	}
}

Map::~Map(){
	//this is left blank intentionally
}

bool Map::slotmap(std::string filename, Console &g_Console){
	bool exception = true;
	std::string pathway = "maps//" + filename;
	std::ifstream map;
	std::string line;
	map.open(pathway);
	if (map.is_open() == true){
		int row = 0;
		while (std::getline(map, line)) {
			for (int col = 0; col < 160; col++) {
				if (line[col] > 160)
					continue;
				else if (row < 40)
					maparray[row][col] = line[col];
				else
					break;
			}
			row++;
		}
		for (int row = 0; row < 40; row++) {
			for (int col = 0; col < 160; col++) {
				if (maparray[row][col] == '#') {
					g_Console.writeToBuffer(col, row, "°±", 0x0f);
				}
				else {
					g_Console.writeToBuffer(col, row, maparray[row][col], 0x0f);
				}
			}
		}
		map.close();
		return true;
	}
	else {
		return false;
	}
}

void Map::drawmap(Console &g_Console) {
	for (int row = 0; row < 40; row++) {
		for (int col = 0; col < 160; col++) {
			if (maparray[row][col] == '#') {
				g_Console.writeToBuffer(col, row, "°±", 0x0f);
			}
			else {
				g_Console.writeToBuffer(col, row, maparray[row][col], 0x0f);
			}
		}
	}
}
void Map::editmap(Console &g_Console,int x, int y,char toreplace){
	maparray[y][x] = toreplace;
}


bool Map::checkread() {
	return read;
}
void Map::changeread(bool status) {
	read = status;
}

bool Map::isoccupied(Console& g_Console, int x, int y){
	if (maparray[y][x] != ' ') {
		return true;
	}
	else {
		return false;
	}
}
