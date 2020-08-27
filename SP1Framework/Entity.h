#pragma once
#include "Framework/console.h"
#include <string>
#include "Map.h"
#include "position.h"

struct MOVEMENTDIRECTION {
	bool UP;
	bool DOWN;
	bool LEFT;
	bool RIGHT;
};

struct direction {
	COORD UP = { 0,1 };
	COORD DOWN = { 0,-1 };
	COORD LEFT = { -1,0 };
	COORD RIGHT = { 1,0 };
};

//direction variable
//                //
////Inside your enemy
//position += variable
//if position + variable have anything
//if not then reverse direction

enum class BULLETDIRECTION {
		B_UP,
		B_DOWN,
		B_LEFT,
		B_RIGHT,
	};

enum class BULLETYPE {
	B_P, // player
	B_C, // corona bullet
	B_B, // 
	B_F //  water bullet
};

class Entity
{

private:
	int health;
	bool alive;
	char symbol;
	Position position;
public:
	~Entity();
	Entity(int health,bool alive, char entitysymbol,int x, int y);

	// move function
	virtual void move(MOVEMENTDIRECTION &movementdir,COORD pos,Map &map) = 0; //Function prototype
	
	//Getters, to get private datamembers
	int getX();
	int getY(); 
	COORD returnPos();
	int gethealth();
	char getsymbol();
	//setters to set private datamembers
	void setpos(COORD pos);
	void sethealth(int health);
	void setalive(bool alive);
	void setsymbol(char symbol);
	virtual void shoot(BULLETDIRECTION bulletdir) =0;
    virtual bool movementcollide(Map &map,int x, int y) = 0;
	virtual void damage(int x)=0;
};