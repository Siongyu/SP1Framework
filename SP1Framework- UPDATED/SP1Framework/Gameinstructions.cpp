#include "Gameinstructions.h"

extern Console g_Console;

void GameInstruction()
{
	COORD c;
	c.X = 0;
	c.Y = 14;
	string line;
	ifstream anotherfile("GameInstructions.txt");
	if (anotherfile.is_open())
	{
		while (getline(anotherfile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		anotherfile.close();
	}
}