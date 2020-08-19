#include "Map.h"

Map::Map():maparray{0} {

	for (int row = 0; row < 60; row++) {
		for (int col = 0; col < 200; col++) {
			maparray[row][col] = ' ';
		}
	}
}

Map::~Map(){
	//this is left blank intentionally
}

int Map::getcamera_x(){
	return camera_x;
}

int Map::getcamera_y(){
	return camera_y;
}

void Map::setcamera(int newx, int newy) {
	camera_x = newx;
	camera_y = newy;
}

void Map::movecamera(int direction,int x, int y){
	switch (direction){
	case 0:
		break;
	case 1: // move up 
		camera_y -= 1;
		break;
	case 2: // move down
		camera_y += 1;
		break;
	case 3: // move left
		camera_x -= 1;
		break;
	case 4: // move right
		camera_x += 1;
		break;
	case 5: // move right up
		camera_x += 1;
		camera_y -= 1;
		break;
	case 6: // move right down
		camera_x += 1;
		camera_y += 1;
		break;
	case 7: // move left up
		camera_x -= 1;
		camera_y -= 1;
		break;
	case 8: // move left down
		camera_x -= 1;
		camera_y += 1;
		break;
	case 9: // up down <-- cancel out
		break;
	case 10: // left right <-- cancel out
		break;
	}
	setcamera(camera_x, camera_y);
}


bool Map::slotmap(std::string filename, Console &g_Console){
	bool exception = true;
	std::string pathway = "maps//" + filename;
	std::ifstream map;
	std::string line;
	map.open(pathway);
	if (map.is_open() == true){
		int row = 0;
		while (std::getline(map, line)){
			for (int col = 0; col < 200; col++) {
				if (line[col] > 200)
					continue;
				else if (row < 60)
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
}


void Map::drawmap(Console &g_Console, int camera_x, int camera_y) {
	//int showx = camera_x;
	//int showy = camera_y;
	//if (showx -160  > 0)
	//	showx -= 160;
	//else
	//	showx = 0;
	//if (showy - 40 > 0)
	//	showy -= 40;
	//else
	//	showy = 0;
	//for (int row = 0; row < camera_y; row++) {
	//	for (int col = 0; col < camera_x; col++) {
	//		if (maparray[row][col] == '#') {
	//			g_Console.writeToBuffer(col, row, "°±", 0x0f);	
	//		}
	//		else {
	//			g_Console.writeToBuffer(col, row, maparray[row][col], 0x0f);
	//		}
	//	}
	//}
	for (int row = 0; row < 40; row++)
	{
		for (int col = 0; col < 160; col++)

		{
			g_Console.writeToBuffer(col, row, maparray[row][col], 0x0f);
		}
	}
}

void Map::editmap(Console& g_Console, int x, int y, char toreplace) {
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





//TO DO LIST
//
//Entities* Player
//Entities* Enemies
//
//checkpoint thingy
//proper render functions
//put player into the maparray.
//
//
//maparray size gon be huge then the
//
//drawmap for loops will be controlled by the camera
//
//
//
//drawmap(Console & g_Console, int camera_x, int camera_y);
//
//for (int row = 0; row < camera_x; row++) {  // find a way to fix the row and col
//	for (int col = 0; col < camera_y{
//
//		}
//}