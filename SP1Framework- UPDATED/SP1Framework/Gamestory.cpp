#include "Gamestory.h"

extern Console g_Console;

void Story()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 3; // Story at y 9
	c.X = g_Console.getConsoleSize().X / 2 - 9;
	g_Console.writeToBuffer(c, "Insert Story line using text file and letters by letters", 0x03);

	c.Y += 3;
	c.X = 0;
	string line;
	ifstream myfile("Story.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		myfile.close();
	}
}