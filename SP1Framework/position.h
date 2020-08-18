#pragma once
class Position
{
private:
	int x;
	int y;

public:
	Position();
	~Position();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setPos(int x, int y);
	Position returnPos();
};