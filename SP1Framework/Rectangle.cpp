#include "Rectangle.h"

void rectangle(Console& g_Console, int x, int y, int width, int height, char ch, WORD bordercolor, WORD buttoncolor, bool fill){
	SHORT X = x;
	SHORT Y = y;
	for (int i = 0; i < height; i++)
	{
		for (int o = 0; o < width; o++)
		{
			if (((i == 0) || (i == height - 1)) && (o != 0) && (o != width - 1))
			{
				g_Console.writeToBuffer(X, Y,32, bordercolor);
			}
			else if ((o != 0) && (o != width - 1) && (0 != height - 1) && (fill != false)) // middle of the rectangle
			{
				g_Console.writeToBuffer(X, Y,32, buttoncolor);
			}
			else if (o == 0) // left side of rectangle
			{
				g_Console.writeToBuffer(X, Y,32, bordercolor);
				g_Console.writeToBuffer(X - 1, Y,32, bordercolor);
			}
			else if (o == width-1) // right side of the rectangle
			{
				g_Console.writeToBuffer(X, Y,32, bordercolor);
				g_Console.writeToBuffer(X + 1, Y,32, bordercolor);
			}
			X += 1;
		}
		X = x;
		Y += 1;
	}
}