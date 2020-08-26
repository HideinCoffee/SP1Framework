#pragma once
#include "Position.h"
#include "Framework/console.h"
#include <string>
#include "Map.h"

struct MOVEMENTDIRECTION {
	bool UP;
	bool DOWN;
	bool LEFT;
	bool RIGHT;
};

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
	Position position;
	int health;
	bool alive;
	char symbol;

public:
	~Entity();
	Entity(int health,bool alive, char entitysymbol);

	// move function
	void move(MOVEMENTDIRECTION movementdir,COORD pos,Map &map); //Function prototype
	
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
	virtual void movementcollide(Map &map,int x, int y) = 0;
	virtual void damage(int x)=0;
};