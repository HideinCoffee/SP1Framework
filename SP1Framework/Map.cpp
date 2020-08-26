#include "Map.h"

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
			for (int col = 0; col < 150; col++) {
				if (line[col] > 150)
					continue;
				else if (row < 150)
					maparray[row][col] = line[col];
				else
					break;
			}
			row++;
		}
		return true;
	}
	else {
		return false;
	}
	/*if (map.is_open() == true) {
		int row = 0;
		for (int  col =0; col < 150;col++)
		if (map.good()) {
			std::getline(map, line);
			std::stringstream ss(line);
			while (std::getline(ss, colvalue, ',')) {
				maparray[row][col] = colvalue;
			}
		}
	}*/
}


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

char* Map::getmaparray() {
	char* ptrtomap = *maparray;
	return ptrtomap;
}




