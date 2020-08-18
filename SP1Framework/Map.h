#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Framework/console.h"
class Map
{
private:
	char maparray[60][200];
	bool read = false;
	int camera_x = 160;
	int camera_y = 40;

public:
	Map();
	~Map();
	// get camera_x value
	int getcamera_x();
	// get camera_y value
	int getcamera_y();
	// set camera
	void setcamera(int newx, int newy);
	// change the camera x and y value
	void movecamera(int direction,int newx ,int newy);

	
// depending on the file it will set the maparray to the contents of the textfile(precautions added to prevent it from crashing if it goes out of index) 
	bool slotmap(std::string filename,Console &g_Console);
// draws out the map from the text file
	void drawmap(Console &g_Console,int camera_x, int camera_y);
// insert the position of the char to replace and what char to replace 
	void editmap(Console &g_Console,int x, int y,char toreplace);
// checks if the text file has been read // true = file read false = file not read
	bool checkread(); 
// checks if the position is occupied true = occupied false = not occupied
	bool isoccupied(Console& g_Console, int x, int y); 
// changes the read value to status
	void changeread(bool status);
};


