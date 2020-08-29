#pragma once
#include "Framework/console.h"
#include <fstream>
#include <sstream>
#include <string>
enum class MAPTILES {
	WALL = '#',
	COIN = '$',
	PATH = ' ',
	TRAP = 'x',
	MOB = 'm',
	NPC = '!',
	BULLET = 'B',
	TRAPBULLET = 'Q',
	PLAYER = 'P',
	TOGGLE = 'T',
	HEALTH = 'H',
	AMMO = 'A',
	DOOR = 'D',
	LAVA = 'L',
	DEFAULT
};

class Map
{
private:
	char maparray[150][150];
public:
	Map();
	~Map();
	// get camera_x value
	// change the camera x and y value
	bool read = false;
	COORD movecamera(int direction,COORD playerpos);

// depending on the file it will set the maparray to the contents of the textfile(precautions added to prevent it from crashing if it goes out of index) 
	bool slotmap(std::string filename,Console &g_Console);
// draws out the map from the text file
//	void drawmap(Console &g_Console,Player &player);
// insert the position of the char to replace and what char to replace 
	void editmap(int x, int y,char toreplace);
// checks if the text file has been read // true = file read false = file not read
	bool checkread(); 
// checks if the position is occupied true = occupied false = not occupied
	bool isoccupied(int x, int y); 
// changes the read value to status
	void changeread(bool status);
// get char
	char getchar(int x, int y);
//	char* getmaparray();
	

};


