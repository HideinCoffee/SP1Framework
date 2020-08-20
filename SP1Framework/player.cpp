#include "player.h"
Player::Player(){
	pos.X = 80;
	pos.Y = 20;
	//default constructor
}
Player::Player(int x, int y) {
	pos.X = x;
	pos.Y = y;
}