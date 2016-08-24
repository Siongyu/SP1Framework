#include "level1.h"
Console g_Console(80, 25, "SP1 Framework");

bool	paused = false;

void renderMap1()
{
	COORD c;

	if (!paused)
	{
		ifstream myfile("LEVEL1.txt");

		if (myfile.is_open())
		{
			for (int i = 0; i < MAP1_HEIGHT; i++)
			{
				for (int j = 0; j < MAP1_WIDTH; j++)
				{
					myfile >> nMap1Array[i][j];
				}
			}
			myfile.close();
			c.Y = -1;
			for (int y = 0; y < MAP1_HEIGHT; y++)
			{
				c.Y += 1;
				c.X = -1;
				for (int x = 0; x < MAP1_WIDTH; x++)
				{
					c.X += 1;
					int nType = nMap1Array[y][x];
					g_Console.writeToBuffer(c, sTileIndex[nType].nCharacter, sTileIndex[nType].nColorCode);
				}
			}

		}
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


}