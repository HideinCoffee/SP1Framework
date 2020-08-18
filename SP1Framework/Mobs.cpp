#include "mobs.h"

Mobs::Mobs()
{
	//Constructor for mobs
}

Mobs::~Mobs()
{
	//destructor for mobs
}

void Mobs::move(std::string direction)
{
	//randomised mob movement section
	bool mobMove = false;
	while (mobMove == false)
	{
		int movementRandomiser = (rand() % 4 + 1); //Makes sure that movementRandomiser != 0
		switch (movementRandomiser)
		{
		case 1:
			if (position.getY() - 1 != 0) //Check for boundaries, so ghost can't move off screen past Array row 0, in the up direction
			{
				position.setPos(position.getX(), position.getY() - 1);
				mobMove = true;
				continue;
			}
			else
			{
				continue;
			}

		case 2:
			if (position.getX() + 1 != 20)
			{
				position.setPos(getX() + 1, getY());
				mobMove = true;
				continue;
			}
			else
			{
				continue;
			}
		case 3:
			if (position.getY() + 1 != 20)
			{
				position.setPos(position.getX(), position.getY() + 1);
				mobMove = true;
				continue;
			}
			else
			{
				continue;
			}
		case 4:
			if (position.getX() - 1 != 0) //Moving left, check for boundaries so ghosts can't move left past Array row 0
			{
				position.setPos(position.getX() - 1, position.getY());
				mobMove = true;
				continue;
			}
			else
			{
				continue;
			}
		}
	}
}
