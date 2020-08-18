#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "Framework/console.h"
class Map
{
private:
	char maparray[40][160];
	bool read = false;
public:
	Map();
	~Map();

// depending on the file it will set the maparray to the contents of the textfile(precautions added to prevent it from crashing if it goes out of index) 
	bool slotmap(std::string filename,Console &g_Console);
// draws out the map from the text file
	void drawmap(Console &g_Console);
// insert the position of the char to replace and what char to replace 
	void editmap(Console &g_Console,int x, int y,char toreplace);
// checks if the text file has been read // true = file read false = file not read
	bool checkread(); 
// checks if the position is occupied true = occupied false = not occupied
	bool isoccupied(Console& g_Console, int x, int y); 
// changes the read value to status
	void changeread(bool status);

};


