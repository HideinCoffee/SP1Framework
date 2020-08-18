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
//##!@#!#!@##!#!@# IMPORTANT for slotmap function the textfile must be precise it cannot exceed the array size OR IT WILL CRASH // remember to put a try except to stop it from crashing
	bool slotmap(std::string filename,Console &g_Console); // sets the map array to the contents of the textfile 

	
  // draws out the map from the text file
	void drawmap(Console &g_Console);
	// insert the position of the char to replace and what char to replace 
	void editmap(Console &g_Console,int x, int y,char toreplace);
	// checks if the text file has been read // true = file read false = file not read
	bool checkread(); 
	// checks if the position is occupied true = occupied false = not occupied
	bool isoccupied(Console& g_Console, int x, int y); 
	void changeread(bool status);
};

