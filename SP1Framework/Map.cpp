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



void Map::movecamera(int direction,Player &player ){
	switch (direction) {
	case 0:
		break;
	case 1: // move up 
		player.pos.Y -= 1;
		break;
	case 2: // move down
		player.pos.Y += 1;
		break;
	case 3: // move left
		player.pos.X -= 1;
		break;
	case 4: // move right
		player.pos.X += 1;
		break;
	}
}

bool Map::slotmap(std::string filename, Console &g_Console)
{
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
				else if (row < 200)
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


void Map::drawmap(Console &g_Console,Player &player) {
	COORD c;
	c.X = 0;
	c.Y = 0;
	for (int row = player.pos.Y - 20; row < player.pos.Y + 20; row++) {
		for (int col = player.pos.X - 80; col < player.pos.X + 80; col++) {
			if (maparray[row][col] == '@') {
				c.Y--;
				g_Console.writeToBuffer(c,maparray[row][col], 0x00);
			}
			else if (maparray[row][col] == '#') {
				g_Console.writeToBuffer(c, maparray[row][col], 0xff);
				c.Y--;
			}
			else
				g_Console.writeToBuffer(c, maparray[row][col], 0x0f);
			c.X++;
		}
		c.X = 0;
		c.Y++;
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

bool Map::isoccupied( int x, int y) {
	if (maparray[y][x] != '@')
	{
		return true;
	}
	else
		return false;
}
		/*if (maparray[y][x] == 'r')
		{
			((maparray[y][x] = 'r') = ' ');
			(maparray[1][150] = 't');
			(maparray[1][151] = 'h');
			(maparray[1][152] = 'i');
			(maparray[1][153] = 's');
			(maparray[2][150] = 'i');
			(maparray[2][151] = 's');
			(maparray[2][152] = ' ');
			(maparray[2][153] = 'a');
			(maparray[3][150] = 't');
			(maparray[3][151] = 'r');
			(maparray[3][152] = 'a');
			(maparray[3][153] = 'i');
			(maparray[3][154] = 'l');
			(maparray[4][150] = 'r');
			(maparray[4][151] = 'u');
			(maparray[4][152] = 'n');
			(maparray[30][30] = '@');
		}
		if (maparray[y][x] == '@')
		{
			((maparray[y][x] = '@') = ' ');
			(maparray[1][150] = ' ');
			(maparray[1][151] = ' ');
			(maparray[1][152] = ' ');
			(maparray[1][153] = ' ');
			(maparray[2][150] = ' ');
			(maparray[2][151] = ' ');
			(maparray[2][152] = ' ');
			(maparray[2][153] = ' ');
			(maparray[3][150] = ' ');
			(maparray[3][151] = ' ');
			(maparray[3][152] = ' ');
			(maparray[3][153] = ' ');
			(maparray[3][154] = ' ');
			(maparray[4][150] = ' ');
			(maparray[4][151] = ' ');
			(maparray[4][152] = ' ');
		}*/






