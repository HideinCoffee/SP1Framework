#pragma once
#include "Entity.h"

class Mobs :public Entity
{
private:



public:

	Mobs();
	~Mobs();
	void move(std::string direction); ///more parameters, but suff here must be added to the entity class
};