#pragma once
#include "Entity.h"
#include <ctime>

class Mobs :public Entity
{
private:

	int tm_sec;

public:

	Mobs();
	~Mobs();
	void move(std::string direction); ///more parameters, but suff here must be added to the entity class

};